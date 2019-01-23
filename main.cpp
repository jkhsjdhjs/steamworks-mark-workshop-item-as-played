#include <iostream>
#include <chrono>
#include <thread>
#include "steam_api.h"

ESteamAPICallFailure setPlayedAndGetResult(PublishedFileId_t fileId) {
    auto call = SteamRemoteStorage()->SetUserPublishedFileAction(fileId, k_EWorkshopFileActionPlayed);
    while(!SteamUtils()->IsAPICallCompleted(call, nullptr))
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return SteamUtils()->GetAPICallFailureReason(call);
}

int main(int argc, char **argv) {
    if(argc == 1) {
        std::cerr << "No steam workshop IDs specified!" << std::endl;
        return 1;
    }
    if(!SteamAPI_Init()) {
        std::cerr << "Failed to initialize SteamAPI!" << std::endl;
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        PublishedFileId_t fileId = std::stoi(argv[i]);
        auto result = setPlayedAndGetResult(fileId);
        if(result == k_ESteamAPICallFailureNone)
            std::cout << "Successfully marked workshop item with ID " << fileId << " as played!" << std::endl;
        else {
            std::cerr << "Error marking workshop item with ID " << fileId << " as played: ";
            if(result == k_ESteamAPICallFailureInvalidHandle
            || result == k_ESteamAPICallFailureMismatchedCallback)
                std::cerr << "Unknown exception. Please notify the author of this tool.";
            else if(result == k_ESteamAPICallFailureNetworkFailure)
                std::cerr << "The connection to the steam servers has been lost.";
            else if(result == k_ESteamAPICallFailureSteamGone)
                std::cerr << "The steam client has stopped responding.";
            std::cerr << std::endl;
            return 1;
        }
    }
    return 0;
}