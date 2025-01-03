#include <bits/stdc++.h>
using namespace std;

void pattern_1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_2(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_3(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<=i; j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}

void pattern_4(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern_5(int n) {
    // for(int i = n; i > 0; i--) {
    //     for(int j = 0; j < i; j++) {
    //         cout << "*" << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n-i); j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern_6(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j <= (n - i + 1);j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}

void pattern_7(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < (n - i); j++) {
            cout << " ";
        }
        for(int j = 0; j < (2 * i + 1); j++) {
            cout << "*";
        }
        for(int j = 1; j < (n - 1); j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_8(int n) {
    // for(int i = n - 1; i >= 0; i--) {
    //     for(int j = 1; j < (n - i); j++) {
    //         cout << " ";
    //     }
    //     for(int j = 0; j < (2 * i + 1); j++) {
    //         cout << "*";
    //     }
    //     for(int j = 1; j < (n - 1); j++) {
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int j = 0; j < (2 * (n - i - 1) + 1); j++) {
            cout << "*";
        }
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_9(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }
        for(int j = 0; j < (2 * i + 1); j++) {
            cout << "*";
        }
        for(int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int j = 0; j < (2 * (n - i) - 1 ); j++) {
            cout << "*";
        }
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_10(int n) {
    for(int i = 1; i <= (2 * n - 1); i++) {
        int stars = i > n ? (2 * n - i) : i;
        for(int j = 0; j < stars; j++) {
            cout << "*";
        } 
        cout << endl;
    }
}

void pattern_11(int n) {
    for(int i = 0; i < n; i++) {
        int start = i % 2 ? 0 : 1;
        for(int j = 0; j <= i; j++) {
            cout << start << " ";
            start = !start;
        }
        cout << endl;
    }
}

void pattern_12(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        for(int j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        for(int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern_13(int n) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << ++num << " " ;
        }
        cout << endl;
    }
}

void pattern_14(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A'; ch <= 'A'+i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern_15(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A'; ch < 'A' + (n-i); ch++ ) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern_16(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << (char) (i + 'A') << " ";
        }
        cout << endl;
    }
}

void pattern_17(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (n - i - 1); j++) cout << "  ";
        
        // for(char ch = 'A'; ch < 'A' + i + 1; ch++) {
        //     cout << ch << " ";
        // }
        // for(char ch = 'A' + i - 1; ch >= 'A'; ch--) {
        //     cout << ch << " ";
        // }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        for(int j = 1; j <= (2*i + 1); j++) {
            cout << ch << " ";
            ch = j > breakpoint ? ch - 1 : ch + 1;
        }

        for(int j = 0; j < (n - i - 1); j++) cout << "  ";
        cout << endl;
    }
}

void pattern_18(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A' + (n - i - 1); ch < 'A' + n; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern_19(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - i; j > 0; j--) {
            cout << "* ";
        }
        for(int j = 0; j < ( 2 * i); j++) {
            cout << "  ";
        }
        for(int j = n - i; j > 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - i; j > 0; j--) {
            cout << "* ";
        }
        for(int j = 0; j < (2*i); j++) {
            cout << "  ";
        }
        for(int j = n - i; j > 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_20(int n) {
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }
    //     for(int j = 0; j < (2 * (n - i - 1)); j++) {
    //         cout << "  ";
    //     }
    //     for(int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // for(int i = n - 2; i >= 0; i--) {
    //     for(int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }
    //     for(int j = 0; j < (2 * (n - i - 1)); j++) {
    //         cout << "  ";
    //     }
    //     for(int j = 0; j <= i; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= (2 * n - 1); i++) {
        int stars = i > n ? 2 * n - i : i;
        for(int j = 0; j < stars; j++) {
            cout << "* ";
        }
        int spaces = i > n ? 2 * (i - n) : 2 * (n - i);
        for(int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        for(int j = 0; j < stars; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_21(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}

void pattern_22(int n) {
    // 2 * n - 1 cols and rows
    // subtract n, form a matrix with value as minimum distance from four directions
    // i, j, (2 * n - 1) - 1 - j, (2 * n - 1) - 1 - i
    for(int i = 0; i < (2 * n - 1); i++) {
        for(int j = 0; j < (2 * n - 1); j++) {
            int top = i;
            int left = j;
            int bottom = (2 * n - 2) - i;
            int right = (2 * n - 2) - j;
            cout << n - min({top, left, bottom, right}) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    cin >> n;
    // pattern_1(n);
    // pattern_2(n);
    // pattern_3(n);
    // pattern_4(n);
    // pattern_5(n);
    // pattern_6(n);
    // pattern_7(n);
    // pattern_8(n);
    // pattern_9(n);
    // pattern_10(n);
    // pattern_11(n);
    // pattern_12(n);
    // pattern_13(n);
    // pattern_14(n);
    // pattern_15(n);
    // pattern_16(n);
    // pattern_17(n);
    // pattern_18(n);
    // pattern_19(n);
    // pattern_20(n);
    // pattern_21(n);
    pattern_22(n);
}