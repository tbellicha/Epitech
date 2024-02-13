/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Main
*/

#include "./nibblerArcade.hpp"

static std::map<char, size_t>XAndYMap(size_t x, size_t y)
{
    std::map<char, size_t> ret = {
        {'x', x},
        {'y', y}
    };

    return ret;
}

static bool checkFruitCanSpawn(std::map<char, size_t> fruit, std::vector<std::map<char, size_t>> snake)
{
    if (fruit['x'] == 0)
        return false;
    for (size_t i = 0; i < snake.size(); i++)
        if (fruit['x'] == snake[i]['x'] && fruit['y'] == snake[i]['y'])
            return false;
    return true;
}

static std::map<char, size_t> makeRandomFruit()
{
    return XAndYMap((std::rand()%GAME_HEIGHT), (std::rand()%GAME_LENGTH));
}

void arcade::game::Nibbler::updateTileMap()
{
    _tileMap.clear();
    _tileMap.push_back(std::string(GAME_LENGTH + 2, '#'));
    for (size_t i = 0; i < GAME_HEIGHT; i++)
        _tileMap.push_back("#" + std::string(GAME_LENGTH, ' ') + "#");
    _tileMap.push_back(std::string(GAME_LENGTH + 2, '#'));
    for (size_t i = 0; i < _snake.size(); i++) {
        if (i == 0)
            _tileMap.at(_snake[i]['x'])[_snake[i]['y']] = CHAR_HEAD;
        else
            _tileMap.at(_snake[i]['x'])[_snake[i]['y']] = CHAR_BODY;
    }
    _tileMap.at(_fruit['x'])[_fruit['y']] = CHAR_FRUIT;
}

arcade::game::Nibbler::Nibbler()
{
    _isExit = false;
    _isStart = false;
    _score = 0;
    for (int i = 0; i < START_SIZE; i++)
        _snake.push_back(XAndYMap(GAME_HEIGHT/2, (GAME_LENGTH/2) - i));
    _fruit = makeRandomFruit();
    while (!checkFruitCanSpawn(_fruit, _snake))
        _fruit = makeRandomFruit();
    updateTileMap();
    _direction = RIGHT;
}
arcade::game::Nibbler::~Nibbler()
{
}

void arcade::game::Nibbler::start()
{
    _isStart = true;
}

void arcade::game::Nibbler::reset()
{
    _isExit = false;
    _isStart = true;
    _gameState = RUNNING;
    _direction = RIGHT;
    _score = 0;
    _snake.clear();
    _fruit.clear();
    for (int i = 0; i < START_SIZE; i++)
        _snake.push_back(XAndYMap(GAME_HEIGHT/2, (GAME_LENGTH/2) - i));
    _fruit = makeRandomFruit();
    while (!checkFruitCanSpawn(_fruit, _snake))
        _fruit = makeRandomFruit();
    updateTileMap();
}

size_t arcade::game::Nibbler::getScore() const
{
    return _score;
}

arcade::game::gameState arcade::game::Nibbler::getGameState() const
{
    return _gameState;
}

void arcade::game::Nibbler::exit()
{
    _gameState = EXIT;
}

std::vector<std::string> arcade::game::Nibbler::getTilemap() const
{
    return _tileMap;
}

bool arcade::game::Nibbler::checkDeath()
{
    if (_direction == UP && (_snake[0]['x'] == 1 || _tileMap[_snake[0]['x'] - 1][_snake[0]['y']] == CHAR_BODY))
        return true;
    if (_direction == DOWN && (_snake[0]['x'] == GAME_LENGTH || _tileMap[_snake[0]['x'] + 1][_snake[0]['y']] == CHAR_BODY))
        return true;
    if (_direction == LEFT && (_snake[0]['y'] == 1 || _tileMap[_snake[0]['x']][_snake[0]['y'] - 1] == CHAR_BODY))
        return true;
    if (_direction == RIGHT && (_snake[0]['y'] == GAME_LENGTH || _tileMap[_snake[0]['x']][_snake[0]['y'] + 1] == CHAR_BODY))
        return true;
    return false;
}

void arcade::game::Nibbler::update(std::vector<arcade::graphical::events> events)
{
    arcade::game::direction nextDir = _direction;
    std::map<char, size_t> snakeTail = {{' ', 0}};

    for (size_t i = 0; i < events.size(); i++) {
        (events.at(i) == arcade::graphical::events::UP) ? (nextDir = UP) : (0);
        (events.at(i) == arcade::graphical::events::DOWN) ? (nextDir = DOWN) : (0);
        (events.at(i) == arcade::graphical::events::LEFT) ? (nextDir = LEFT) : (0);
        (events.at(i) == arcade::graphical::events::RIGHT) ? (nextDir = RIGHT) : (0);
    }
    if (!_isStart || _gameState == OVER)
        return;
    if (((_direction == UP || _direction == DOWN) && (nextDir == LEFT || nextDir == RIGHT)) ||
    ((_direction == RIGHT || _direction == LEFT) && (nextDir == UP || nextDir == DOWN)))
        _direction = nextDir;
    if (checkDeath()) {
        _gameState = OVER;
        return;
    }
    snakeTail = XAndYMap(_snake[_snake.size() - 1]['x'], _snake[_snake.size() - 1]['y']);
    for (size_t i = _snake.size() - 1; i > 0; i--)
        _snake[i] = XAndYMap(_snake[i-1]['x'], _snake[i-1]['y']);
    if (_direction == UP)
        _snake[0]['x'] = _snake[0]['x'] - 1;
    if (_direction == DOWN)
        _snake[0]['x'] = _snake[0]['x'] + 1;
    if (_direction == RIGHT)
        _snake[0]['y'] = _snake[0]['y'] + 1;
    if (_direction == LEFT)
        _snake[0]['y'] = _snake[0]['y'] - 1;
    if (_snake[0]['x'] == _fruit['x'] && _snake[0]['y'] == _fruit['y']) {
        _score++;
        _snake.push_back(snakeTail);
        _fruit = makeRandomFruit();
        while (!checkFruitCanSpawn(_fruit, _snake))
            _fruit = makeRandomFruit();
    }
    updateTileMap();
}

extern "C" arcade::game::IGame *createGame()
{
    return new arcade::game::Nibbler;
}

extern "C" void destroyGame(arcade::game::IGame *d)
{
    delete d;
}