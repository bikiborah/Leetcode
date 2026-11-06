class Solution {
private:
    int precedence(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else return 1;
    }

    int solve(int x, int y, char op) {
        if (op == '+') return x + y;
        else if (op == '-') return x - y;
        else if (op == '*') return x * y;
        else if (op == '/') return x / y;

        return 0;
    }

    void evaluate(stack<int>& values, stack<char>& ops) {
        int y = values.top();
        values.pop();

        int x = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(solve(x, y, op));
    }

public:
    int calculate(string s) {
        stack<int> values;
        stack<char> ops;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ') continue;

            // Extract complete number
            if (isdigit(s[i])) {
                int num = 0;

                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                values.push(num);
                i--;
            }

            // Opening bracket
            else if (s[i] == '(') {
                ops.push(s[i]);
            }

            // Closing bracket
            else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    evaluate(values, ops);
                }

                if (!ops.empty()) {
                    ops.pop();
                }
            }

            // Operators
            else {
                while (!ops.empty() && ops.top() != '(' &&
                       precedence(ops.top()) >= precedence(s[i])) {
                    evaluate(values, ops);
                }

                ops.push(s[i]);
            }
        }

        // Evaluate remaining operators
        while (!ops.empty()) {
            evaluate(values, ops);
        }

        return values.top();
    }
};