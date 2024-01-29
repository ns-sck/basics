#include <iostream>
#include <vector>

int main() {
    std::string first_name = "winterva";
    std::string second_name = "inzva";

    std::vector<std::vector<int>> dp(second_name.length() + 1, std::vector<int>(first_name.length() + 1, 0));

    for (int i = 1; i <= second_name.length(); ++i) {
        for (int j = 1; j <= first_name.length(); ++j) {
            if (first_name[j - 1] == second_name[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    // Print the dp array
    for (int i = 0; i <= second_name.length(); ++i) {
        for (int j = 0; j <= first_name.length(); ++j) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}