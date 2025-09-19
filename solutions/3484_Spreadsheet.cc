// Sep. 18th, 2025

class Spreadsheet {
private:
    pair<int,int> getPos(string cell) {
        int c = cell[0]-'A';
        int r = std::stoi(cell.substr(1));
        return {c,r};
    }

    // parse the formula into cells and individual values
    vector<string> parseFormula(string formula) {
        formula = formula.substr(1);    // strip the equal sign
        stringstream stream(formula);
        string tok;
        vector<string> elements;
        while (getline(stream, tok, '+')) {
            elements.push_back(tok);
        }

        return elements;
    }

public:
    vector<vector<int>> ss;

    Spreadsheet(int rows) {
        ss.assign(26, vector<int>(rows+1, 0));
    }
    
    void setCell(string cell, int value) {
        auto [c,r] = getPos(cell);
        ss[c][r] = value;
    }
    
    void resetCell(string cell) {
        auto [c,r] = getPos(cell);
        ss[c][r] = 0;
    }
    
    int getValue(string formula) {
        vector<string> elements = parseFormula(formula);
        int ans=0;
        for (const string& e : elements) {
            // cell case
            if (isalpha(e[0])) {
                auto [c,r] = getPos(e);
                ans += ss[c][r];
            }

            // integer case
            else {
                ans += stoi(e);
            }
        }

        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */