 for(int i = 0; i < n; i ++){
        s[n - 2][i] = 'W';
        s[i][n - 2] = 'W';
    }
    int len = n - 2;
    for(int k = 0; k < n - 2; k ++){
        for(int i = k; i < len; i ++){
            s[k][i] = k % 2 == 0 ? 'W' : 'B';
            s[i][k] = k % 2 == 0 ? 'W' : 'B';
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << s[i][j];
        }
        cout << endl;
    }