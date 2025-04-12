            genPal(palin, left + 1, right - 1, divisor, total);
        }
    }

    ll countGoodIntegers(int total, int divisor) {
        vector<int> palin(total);
        genPal(palin, 0, total - 1, divisor, total);
        return res;
    }
};