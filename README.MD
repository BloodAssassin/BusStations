# Bus Station Distance Calculator

A C++ console application that calculates the distance between bus stations using 2D coordinates.

## Features

- **Station Management**: Predefined bus stations with names and coordinates
- **Distance Calculation**: Calculates Euclidean distance between any two stations
- **Case-Insensitive Search**: Find stations regardless of input case
- **Error Handling**: Validates station names and provides helpful error messages

## Project Structure

```
Bus stations/
├── main.cpp        # Main application logic
├── BusStation.h    # BusStation class definition
├── Vector2.h       # 2D vector class with distance calculation
└── README.MD       # This file
```

## Classes

### `BusStation`
- Represents a bus station with a name and 2D location
- **Constructor**: `BusStation(name, x, y)`
- **Methods**:
  - `getName()`: Returns station name
  - `getLocation()`: Returns Vector2 position

### `Vector2`
- Represents a 2D coordinate point
- **Constructor**: `Vector2(x, y)` with default values (0, 0)
- **Static Methods**:
  - `Distance(Vector2 a, Vector2 b)`: Calculates distance between two points

## How to Build

```bash
# Compile the project
g++ main.cpp -o bus

# Run the executable
./bus
```

## Usage

1. Run the program
2. View the list of available stations:
   - MAS (0, 12)
   - SAS (15, 10)
   - BAS (32, 5)
3. Enter the names of two stations when prompted
4. The program will display the distance between them in "clicks"

### Example
```
===== Bus Station Distancer =====
Stations:
1. MAS
2. SAS
3. BAS

Station 1 (name): mas
Station 2 (name): SAS
Distance between MAS and SAS is 15 clicks.
```

## Technical Notes

- Uses Euclidean distance formula: `√((x₂-x₁)² + (y₂-y₁)²)`
- Case-insensitive station lookup using `std::transform` and `std::tolower`
- Memory efficient: Uses stack-allocated objects (no dynamic allocation)
- Modern C++ features: `std::optional`, `std::array`, lambda functions

## Future Improvements

- [ ] Add more bus stations
- [ ] Load stations from external file
- [ ] Support for adding custom stations at runtime