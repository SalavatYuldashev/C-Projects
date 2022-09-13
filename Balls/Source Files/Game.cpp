// Created by Salavat on 09.09.2022.
#include "../Header Files/Game.h"

//Constructors and Destructors
Game::Game()
{
    initVariables();
    initWindow();
    initFont();
    initText();
}

Game::~Game()
{
    delete Game::window;
}

//Private functions
void Game::initWindow()
{
    videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Balls", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);
}
void Game::initVariables()
{
    endGame = false;
    spawnTimerMax = 10.f;
    spawnTimer = spawnTimerMax;
    maxSwagBalls = 30;
    points = 0;
}

//Public functions
void Game::render()
{
    window->clear();

    //Render stuff
    player->Player::render(window);
    for (auto i : swagBalls)
    {
        i.render(*window);
    }
    renderGUI(window);

    //Render end text
    if (endGame)
    {
        window->draw(endGameText);
    }

    window->display();
}
void Game::update()
{
    pollEvents();
    if (endGame == false)
    {
        spawnSwagBalls();
        updatePlayer();
        updateCollision();
        updateGUI();
    }

}
bool Game::running() const
{
    return window->isOpen() /*&& !getEndGame()*/;
}
void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window->close();
            }
            break;
        }
    }
}
void Game::spawnSwagBalls()
{
    //Timer
    if (spawnTimerMax < spawnTimer)
    {
        spawnTimer += 0.1f;
    }
    else
    {
        if (swagBalls.size() < maxSwagBalls)
        {
            swagBalls.push_back(SwagBall(*this->window, randBallType()));
            spawnTimer = 0.f;
        }

    }
}
void Game::updateCollision()
{
    for (size_t i = 0; i < swagBalls.size(); i++)
    {
        if (player->getShape().getGlobalBounds().
            intersects(swagBalls[i].getShape().getGlobalBounds()))
        {
            std::cout << static_cast<int>(swagBalls[i].getType()) << std::endl;
            switch (swagBalls[i].getType())
            {
            case SwagBallTypes::DAMAGING:
                player->takeDamage(1);
                break;
            case SwagBallTypes::DEFAULT:
                points++; //Add points
                break;
            case SwagBallTypes::HEALING:
                player->gainHealth(1);
                break;
            }
            //Remove the ball
            swagBalls.erase(swagBalls.begin() + i);
        }
    }

}
void Game::initFont()
{
    if (font.loadFromFile("../Fonts/Pixellettersfull.ttf"))
    {
        std::cout << "LoadFont" << std::endl;
    }
}
void Game::initText()
{
    guiText.setFont(font);
    guiText.setFillColor(sf::Color::White);
    guiText.setCharacterSize(32);

    //End game text
    endGameText.setFont(font);
    endGameText.setFillColor(sf::Color::Magenta);
    endGameText.setCharacterSize(128);
    endGameText.setPosition(130.f, 200.f);
    endGameText.setString("GAME OVER!");

}
void Game::renderGUI(sf::RenderTarget* target)
{
    target->draw(guiText);
}
void Game::updateGUI()
{
    std::stringstream ss;
    ss << "  POINTS: " << points << std::endl
       << "  HP: " << player->getHP() << " / " << player->getHPMax();
    guiText.setString(ss.str());
}
const int Game::randBallType()
{
    int type = SwagBallTypes::DEFAULT;
    int randValue = rand() % 100 + 1;
    if (randValue >= 70 && randValue <= 90)
    {
        type = SwagBallTypes::DAMAGING;
    }
    if (randValue >= 90 && randValue <= 100)
    {
        type = SwagBallTypes::HEALING;
    }
    return type;
}
const bool& Game::getEndGame() const
{
    return endGame;
}
void Game::updatePlayer()
{
    player->update(window);
    if (player->getHP() <= 0)
    {
        endGame = true;
    }
}
