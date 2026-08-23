#include <iostream>
#include <fstream>
#include <vector>


double dotProd(int x, int y, int x1, int y1, int x2, int y2) {
    return (y2-y1) * (x-x1) + (x1-x2)*(y-y1);
}


bool doesContainOrigin(double x1, double y1, double x2, double y2, double x3, double y3) {
    double d = (y2-y3) * (x1-x3) + (x3-x2)*(y1-y3);

    double a = ((y2-y3) * (0-x3) + (x3-x2)*(0-y3)) / d;
    double b = ((y3-y1) * (0-x3) + (x1-x3)*(0-y3)) / d;
    double c = 1 - a - b;

    return (0 <= a && a <= 1) && (0 <= b && b <= 1) && (0 <= c && c <= 1);
}


int main() {
    int ans = 0;

    std::ifstream numFile("triangles.txt");
    std::string line;

    while (std::getline(numFile, line)) {
        std::vector<std::string> inp;
        inp.reserve(6);

        int continuation = 0;
        std::string current = "";

        for (int i = 0; i < 6; ++i) {
            for (int j = continuation; j < line.length(); ++j) {
                if (line[j] == ',') {
                    continuation = j+1;
                    break;
                }

                current += line[j];
            }

            inp.push_back(current);
            current = "";
        }

        ans += doesContainOrigin(std::stoi(inp[0]), std::stoi(inp[1]), std::stoi(inp[2]), std::stoi(inp[3]), std::stoi(inp[4]), std::stoi(inp[5]));
    }

    numFile.close();
    
    std::cout << ans;

    return 0;
}