#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(){
    sf::VideoMode vm(800, 600);

    sf::RenderWindow window(vm, "fonts");
    window.setFramerateLimit(20);

    sf::Font font;
    if(!font.loadFromFile("../Ubuntu-B.ttf")){
        std::cout << "font did not loaded" << std::endl;
    }

    sf::Text text1("", font);
    text1.setString("MAKSIM");
    text1.setPosition(100, 100);
    text1.setCharacterSize(60);
    text1.setFillColor(sf::Color(0,255,100));

    sf::Image img;
    img.loadFromFile("../jpg.jpeg");
    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Shader shader;
    shader.loadFromFile("../gaussian_blur.frag", sf::Shader::Fragment);
    // shader.setUniform("texture", texture);
    shader.setUniform("radius", 0.02f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed  || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
                window.close();
                break;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){
                sf::Vector2u windowSize = window.getSize();
                sf::Texture screenshotTexture;
                screenshotTexture.create(windowSize.x, windowSize.y);
                screenshotTexture.update(window);
                screenshotTexture.copyToImage().saveToFile("screen.png");
            }
        }

        window.clear();

        window.draw(sprite);
        // window.draw(sprite, &shader);
        // window.draw(text1);
        window.draw(text1, &shader);
        window.display();
    }

    return 0;
}