/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Main
*/

#include "./pacmanArcade.hpp"
#include <fstream>

static std::map<char, size_t>XAndYMap(size_t x, size_t y)
{
    std::map<char, size_t> ret = {
        {'x', x},
        {'y', y}
    };

    return ret;
}

static std::map<char, size_t>GumXAndYMap(size_t x, size_t y, char c)
{
    std::map<char, size_t> ret = {
        {'x', x},
        {'y', y},
        {'v', (c == '.') + (c == 'o') * 15}
    };

    return ret;
}

static std::map<char, size_t>GhostXAndYMap(size_t x, size_t y, size_t state)
{
    std::map<char, size_t> ret = {
        {'x', x},
        {'y', y},
        {'s', state}
    };

    return ret;
}

static std::vector<std::string> getTileMapFromFile(void)
{
    std::vector<std::string> ret = {};
    std::ifstream mapFile(MAP_LOCATION);
    std::string temp = "";

    while (getline(mapFile, temp))
        ret.push_back(temp);
    return ret;
}

arcade::game::Pacman::Pacman()
{
    reset();
}

void arcade::game::Pacman::re()
{
    _isExit = false;
    _isStart = true;
    _gameState = RUNNING;
    _timer = time(NULL);
    _score = 0;
    _tileMap.clear();
    _tileMap = getTileMapFromFile();
    _gums.clear();
    _ghosts.clear();
    _ghostDir.clear();

    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_PACMAN)
                _pacman = XAndYMap(i, j);
    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_GUM || _tileMap[i][j] == CHAR_PACGUM)
                _gums.push_back(GumXAndYMap(i, j, _tileMap[i][j]));
    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_GHOST) {
                _ghosts.push_back(GhostXAndYMap(i, j, 1));
                _ghostDir.push_back((arcade::game::direction)(rand()%4 + 1));
            }
}

void arcade::game::Pacman::winReset()
{
    _isExit = false;
    _isStart = true;
    _gameState = RUNNING;
    _timer = time(NULL);
    _tileMap.clear();
    _tileMap = getTileMapFromFile();
    _gums.clear();
    _ghosts.clear();
    _ghostDir.clear();

    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_PACMAN)
                _pacman = XAndYMap(i, j);
    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_GUM || _tileMap[i][j] == CHAR_PACGUM)
                _gums.push_back(GumXAndYMap(i, j, _tileMap[i][j]));
    for (size_t i = 0; i < _tileMap.size(); i++)
        for (size_t j = 0; j < _tileMap[i].size(); j++)
            if (_tileMap[i][j] == CHAR_GHOST) {
                _ghosts.push_back(GhostXAndYMap(i, j, 1));
                _ghostDir.push_back((arcade::game::direction)(rand()%4 + 1));
            }
}

arcade::game::Pacman::~Pacman()
{

}

void arcade::game::Pacman::start()
{
    _isStart = true;
    _timer = time(NULL);
}

static int oneOrNone(arcade::game::direction a, arcade::game::direction b)
{
    if (a == b)
        return 1;
    return 0;
}

static char checkGum(std::map<char, size_t> ghost, std::vector<std::map<char, size_t>> gums)
{
    for (size_t i = 0; i < gums.size(); i++)
        if (gums[i]['x'] == ghost['x'] && gums[i]['y'] == ghost['y']) {
            if (gums[i]['v'] == 1)
                return '.';
            return 'o';
        }
    return ' ';
}

bool arcade::game::Pacman::checkDeath()
{
    for (size_t i = 0; i < _ghosts.size(); i++)
        if (_ghosts[i]['x'] == _pacman['x'] && _ghosts[i]['y'] == _pacman['y'] && _ghosts[i]['s'] == 1)
            return true;
    return false;
}

void arcade::game::Pacman::update(std::vector<arcade::graphical::events> events)
{
    arcade::game::direction nextDir = _direction;

    for (size_t i = 0; i < events.size(); i++) {
        (events.at(i) == arcade::graphical::events::UP) ? (nextDir = UP) : (0);
        (events.at(i) == arcade::graphical::events::DOWN) ? (nextDir = DOWN) : (0);
        (events.at(i) == arcade::graphical::events::LEFT) ? (nextDir = LEFT) : (0);
        (events.at(i) == arcade::graphical::events::RIGHT) ? (nextDir = RIGHT) : (0);
        if (events.at(i) == arcade::graphical::events::RESTART) {
            reset();
            return;
        }
    }
    if (!_isStart || _gameState == OVER)
        return;
    if (time(NULL) - _timer >= 10 && _tileMap[10][8] == CHAR_WALL && _tileMap[10][12] == CHAR_WALL) {
        _tileMap[10][8] = ' ';
        _tileMap[10][12] = ' ';
    }
    _direction = nextDir;
    if (_pacman['y'] == 0 && _direction == LEFT) {
        _tileMap[_pacman['x']][_pacman['y']] = ' ';
        _pacman['y'] = _tileMap[0].size() - 1;
    } else if (_pacman['y'] == _tileMap[0].size() - 1 && _direction == RIGHT) {
        _tileMap[_pacman['x']][_pacman['y']] = ' ';
        _pacman['y'] = 0;
    } else if (_tileMap[_pacman['x'] + oneOrNone(_direction, DOWN) - oneOrNone(_direction, UP)][_pacman['y'] + oneOrNone(_direction, RIGHT) - oneOrNone(_direction, LEFT)] != CHAR_WALL) {
        _tileMap[_pacman['x']][_pacman['y']] = ' ';
        _pacman['x'] = (int)_pacman['x'] + oneOrNone(_direction, DOWN) - oneOrNone(_direction, UP);
        _pacman['y'] = (int)_pacman['y'] + oneOrNone(_direction, RIGHT) - oneOrNone(_direction, LEFT);
    }
    if (checkDeath()) {
        _gameState = OVER;
        return;
    }
    for (size_t i = 0; i < _ghosts.size(); i++) {
        while (_tileMap[_ghosts[i]['x'] + oneOrNone(_ghostDir[i], DOWN) - oneOrNone(_ghostDir[i], UP)][_ghosts[i]['y'] + oneOrNone(_ghostDir[i], RIGHT) - oneOrNone(_ghostDir[i], LEFT)] == CHAR_WALL) {
            _ghostDir[i] = (arcade::game::direction)(rand()%4 + 1);
        }
        if (_tileMap[_ghosts[i]['x'] + oneOrNone(_ghostDir[i], DOWN) - oneOrNone(_ghostDir[i], UP)][_ghosts[i]['y'] + oneOrNone(_ghostDir[i], RIGHT) - oneOrNone(_ghostDir[i], LEFT)] != CHAR_WALL) {
            _tileMap[_ghosts[i]['x']][_ghosts[i]['y']] = checkGum(_ghosts[i], _gums);
            _ghosts[i]['x'] = (int)_ghosts[i]['x'] + oneOrNone(_ghostDir[i], DOWN) - oneOrNone(_ghostDir[i], UP);
            _ghosts[i]['y'] = (int)_ghosts[i]['y'] + oneOrNone(_ghostDir[i], RIGHT) - oneOrNone(_ghostDir[i], LEFT);
        }
    }
    if (checkDeath()) {
        _gameState = OVER;
        return;
    }
    if (_tileMap[_pacman['x']][_pacman['y']] == CHAR_GUM)
        _score++;
    if (_tileMap[_pacman['x']][_pacman['y']] == CHAR_PACGUM)
        _score += 15;
    for (size_t i = 0; i < _gums.size(); i++)
        if (_gums[i]['x'] == _pacman['x'] && _gums[i]['y'] == _pacman['y'])
            _gums.erase(_gums.begin() + i);
    if (_gums.empty()) {
        winReset();
    }
    updateTileMap();
}

size_t arcade::game::Pacman::getScore() const
{
    return _score;
}

arcade::game::gameState arcade::game::Pacman::getGameState() const
{
    return _gameState;
}

void arcade::game::Pacman::exit()
{
    _gameState = EXIT;
}

void arcade::game::Pacman::updateTileMap()
{
    _tileMap[_pacman['x']][_pacman['y']] = CHAR_PACMAN;
    for (size_t i = 0; i < _ghosts.size(); i++)
        _tileMap[_ghosts[i]['x']][_ghosts[i]['y']] = CHAR_GHOST;
}

std::vector<std::string> arcade::game::Pacman::getTilemap() const
{
    return _tileMap;
}

extern "C" arcade::game::IGame *createGame()
{
    return new arcade::game::Pacman;
}

extern "C" void destroyGame(arcade::game::IGame *d)
{
    delete d;
}