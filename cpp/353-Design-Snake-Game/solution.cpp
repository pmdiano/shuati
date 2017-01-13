class SnakeGame {
    class myHash {
    public:
        size_t operator()(const pair<int, int> &point) const {
            hash<int> h;
            return h(h(point.first) ^ (h(point.second) - 1));
        }
    };

    vector<pair<int, int>> snake;
    vector<pair<int, int>> food;
    unordered_set<pair<int, int>, myHash> board;
    int fidx;   // index of next food
    int width, height;
    bool game_over;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food)
        : fidx(0)
        , game_over(false) {
        this->snake.push_back(make_pair(0, 0));
        this->food = food;
        this->width = width;
        this->height = height;
        board.insert(make_pair(0, 0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (game_over) {
            return -1;
        }
        auto next = snake.back();
        switch(direction[0]) {
            case 'U': --next.first; break;
            case 'D': ++next.first; break;
            case 'R': ++next.second; break;
            case 'L': --next.second; break;
            default: break;
        }

        if (next.first < 0 || next.first >= height ||
            next.second < 0 || next.second >= width) {
            game_over = true;
            return -1;
        }

        if (fidx < food.size() &&
            food[fidx].first == next.first &&
            food[fidx].second == next.second) {
            ++fidx;
        } else {
            board.erase(snake[0]);
            snake.erase(snake.begin());
        }

        if (board.count(next)) {
            game_over = true;
            return -1;
        }
        snake.push_back(next);
        board.insert(next);

        return snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */