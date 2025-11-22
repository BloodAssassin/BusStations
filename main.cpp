#include "BusStation.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <optional>
#include <string>

std::string toLowerCopy(const std::string &s) {
  std::string copy = s;
  std::transform(copy.begin(), copy.end(), copy.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return copy;
}

int main() {
  std::string station1Name;
  std::string station2Name;
  std::optional<BusStation> station1;
  std::optional<BusStation> station2;
  std::array<BusStation, 3> stations{BusStation("MAS", 0, 12),
                                     BusStation("SAS", 15, 10),
                                     BusStation("BAS", 32, 5)};

  std::string programName = "Bus Station Distancer";
  std::cout << "===== " << programName << " =====" << std::endl;

  std::cout << "Stations: " << std::endl;
  for (int i = 0; i < stations.size(); i++) {
    std::cout << i + 1 << ". " << stations[i].getName() << std::endl;
  }
  std::cout << std::endl; // Newline (for the sake of elegancy)

  // Ask the user between which stations they need distance of
  std::cout << "Station 1 (name): ";
  std::cin >> station1Name;
  std::cout << "Station 2 (name): ";
  std::cin >> station2Name;

  for (int i = 0; i < stations.size(); i++) {
    std::string stationName = toLowerCopy(stations[i].getName());
    std::string smallStation1Name = toLowerCopy(station1Name);
    std::string smallStation2Name = toLowerCopy(station2Name);

    if (stationName == smallStation1Name) {
      station1 = stations[i];
    } else if (stationName == smallStation2Name) {
      station2 = stations[i];
    }
  }

  std::cout << std::endl; // Newline (for the sake of elegancy)

  // Check if we found both
  if (station1.has_value() && station2.has_value()) {
    // Calculate the distance if both have been found
    int distance = Vector2::Distance(station1.value().getLocation(),
                                     station2.value().getLocation());
    std::cout << "Distance between " << station1.value().getName() << " and "
              << station2.value().getName() << " is " << distance << " clicks."
              << std::endl;
  } else if (!station1.has_value() && !station2.has_value()) {
    std::cout << "None of the stations have been found!" << std::endl;
  } else if (!station1.has_value()) {
    std::cout << "Station " << station1Name << " hasn't been found!"
              << std::endl;
  } else if (!station2.has_value()) {
    std::cout << "Station " << station2Name << " hasn't been found!"
              << std::endl;
  }

  return 0;
}