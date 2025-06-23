method 1
vector<int> v = {10, 5, 8, 20, 2, 7};

    // Find minimum element
    int minValue = *min_element(v.begin(), v.end());

    // Find maximum element
    int maxValue = *max_element(v.begin(), v.end());

method 2
vector<int> v = {10, 5, 8, 20, 2, 7};

    int minValue = v[0];
    int maxValue = v[0];

    for (int i = 1; i < v.size(); i++) {
        minValue = min(minValue, v[i]);
        maxValue = max(maxValue, v[i]);
    }
method 3
 vector<int> v = {10, 5, 8, 20, 2, 7};
    sort(v.begin(), v.end());

    int minValue = v[0];             
    int maxValue = v[v.size() - 1];  
