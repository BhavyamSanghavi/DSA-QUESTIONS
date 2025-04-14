                    if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[k]-arr[i])<=c) ans++;
                }
            }
        }
        return ans;
    }
};