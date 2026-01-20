class Solution {
  public:
    string content="";
    string last="";
    void append(char x) {
        content.push_back(x);
    }

    void undo() {
        last.push_back(content[content.size()-1]);
        content.pop_back();
    }

    void redo() {
        content.push_back(last[last.size()-1]);
        last.pop_back();
    }

    string read() {
        return content;
    }
};
