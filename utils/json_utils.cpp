#include <iostream>
#include <fstream>
#include <string>

// Include the library (adjust path if you put it in a subfolder)
#include "json.hpp"

// For convenience
using json = nlohmann::json;

int read_json(int *message_id, int *timestamp, ) {
    // 1. Open the file stream
    std::ifstream f("config.json");

    if (!f.is_open()) {
        std::cerr << "Could not open config.json!" << std::endl;
        return 1;
    }

    // 2. Parse the file into a JSON object
    // The library handles parsing directly from the stream
    json data;
    try {
        data = json::parse(f);
    } catch (const json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        return 1;
    }

    // 3. Fill your variables
    // You can access fields using brackets ["key"]
    std::string serverName = data["server_name"];
    int maxPlayers = data["max_players"];
    double gravity = data["gravity"];

    // 4. Accessing nested objects
    bool spectatorMode = data["features"]["spectator_mode"];

    // Output to verify
    std::cout << "Server: " << serverName << "\n";
    std::cout << "Players: " << maxPlayers << "\n";
    std::cout << "Gravity: " << gravity << "\n";
    std::cout << "Spectator: " << (spectatorMode ? "On" : "Off") << std::endl;

    return 0;
}