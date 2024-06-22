# Integrated Real-time Transfer Protocol

for realtime p2p chating and IOT information transmission.

MongoDB required.

### Build
```
sh ./build.sh
```

### Server

Go to `build` folder.
```
./server
```

### Configuration
Configuration file is `config.json`.
```
{
    "host":"localhost",
    "port": 8800,
    "mongo":{
        "host":"localhost",
        "port":27017,
        "database":"test"
    }
}
```
