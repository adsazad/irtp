# Integrated Real-time Transfer Protocol

for realtime p2p chating and IOT information transmission.

MongoDB required.

### Build
```shell
sh ./build.sh
```

### Server

Go to `build` folder.
```shell
./server
```

### Configuration
Configuration file is `config.json`.
```json
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
