#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// --- Data Structure ---
struct Location {
    int id;
    string name;
    double lat;
    double lon;
};

// --- Class: LocationDatabase ---
class LocationDatabase {
private:
    vector<Location> locations;

public:
    LocationDatabase() {
        // CURATED POI DATASET (High Priority Nodes)
        locations = {
            // Historic
            {0, "Minar-e-Pakistan", 31.5894, 74.3098},
            {1, "Lahore Fort", 31.5880, 74.3150},
            {2, "Badshahi Mosque", 31.5878, 74.3085},
            // Parks
            {4, "Lahore Zoo", 31.5562, 74.3259},
            {5, "Jilani Park (Race Course)", 31.5450, 74.3400},
            {6, "Greater Iqbal Park", 31.5900, 74.3100},
            // Transport
            {10, "Lahore Railway Station", 31.5772, 74.3357},
            {11, "Allama Iqbal Airport", 31.5204, 74.4109},
            {12, "Thokar Niaz Baig", 31.4700, 74.2400},
            // Malls & Commercial
            {20, "Liberty Market", 31.5102, 74.3441},
            {21, "Emporium Mall", 31.4665, 74.2660},
            {22, "Packages Mall", 31.4820, 74.3680},
            {23, "Mall of Lahore", 31.5350, 74.3750},
            {26, "MM Alam Road", 31.5150, 74.3480},
            // Education (Universities)
            {30, "LUMS University", 31.4707, 74.4098},
            {31, "UET Lahore", 31.5780, 74.3550},
            {32, "Punjab University (New Campus)", 31.4960, 74.3070},
            {33, "COMSATS Lahore", 31.4050, 74.2100},
            {34, "GC University", 31.5710, 74.3100},
            // Health
            {40, "Jinnah Hospital", 31.4860, 74.2960},
            {41, "Doctors Hospital", 31.4800, 74.2800},
            {42, "Services Hospital", 31.5430, 74.3360},
            // Residential Areas
            {50, "Bahria Town (Eiffel Tower)", 31.3650, 74.1850},
            {52, "DHA Phase 3 (Y Block)", 31.4780, 74.3750},
            {53, "DHA Phase 5", 31.4580, 74.4200},
            {55, "Johar Town (G1 Market)", 31.4623, 74.2936},
            {62, "Gulberg Main Blvd", 31.5200, 74.3450}
        };
    }

    void generateFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "const mapLocations = [\n";
            for (const auto& loc : locations) {
                file << "  { id: " << loc.id << ", name: \"" << loc.name << "\", lat: " << loc.lat << ", lon: " << loc.lon << " },\n";
            }
            file << "];\n";
            file.close();
            cout << "SUCCESS: '" << filename << "' generated successfully." << endl;
        } else {
            cout << "Error: Could not write file." << endl;
        }
    }
};

int main() {
    LocationDatabase db;
    db.generateFile("locations.js");
    return 0;
}