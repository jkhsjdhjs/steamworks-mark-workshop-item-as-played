# steamworks-mark-workshop-item-as-played
Small tool to mark workshop items as played.
Useful if you face issues like [ValveSoftware/portal2#147](https://github.com/ValveSoftware/portal2/issues/147).

## Installation
```
git clone https://github.com/jkhsjdhjs/steamworks-mark-workshop-item-as-played
cd steamworks-mark-workshop-item-as-played
cmake .
make
```

## Usage
- Get the ID of the item(s) you want to mark as played.  
For instance: If the workshop link looks like `https://steamcommunity.com/sharedfiles/filedetails/?id=220115320` the ID is `220115320`.
- Write the app id of the game to `steam_appid.txt` (Portal 2 has the app id `620`).
- Ensure your steam client is running.
- Run `./steamworks-mark-workshop-item-as-played [<workshop id>]`.  
For instance `./steamworks-mark-workshop-item-as-played 139337964 220115320` will mark the maps `1960` and `1960 (revised)` as played.
