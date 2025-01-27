#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Entity.h"
#include "../Input/ToggleKey.h"
#include "../Item/ItemStack.h"

class Keyboard;
class World;
class RenderMaster;

class Player : public Entity {
  public:
    Player(const sf::RenderWindow &window);

    void handleInput(const sf::RenderWindow &window, Keyboard &keyboard);

    void update(float dt, World &wolrd);
    void collide(World &world, const glm::vec3 &vel, float dt);

    void addItem(const Material &material);

    void draw(RenderMaster &master);

    ItemStack &getHeldItems();

  private:
    void jump();

    void keyboardInput(Keyboard &keyboard);
    void mouseInput(const sf::RenderWindow &window);
    bool m_isOnGround = false;
    bool m_isFlying = false;

    std::vector<ItemStack> m_items;
    std::vector<sf::Text> m_itemText;
    sf::Texture m_chTexture;
    sf::Sprite m_crosshair;
    sf::Text m_posPrint;
    int m_heldItem = 0;

    ToggleKey m_itemDown;
    ToggleKey m_itemUp;
    ToggleKey m_flyKey;

    ToggleKey m_num1;
    ToggleKey m_num2;
    ToggleKey m_num3;
    ToggleKey m_num4;
    ToggleKey m_num5;

    glm::vec3 m_acceleration;
};

#endif // PLAYER_H_INCLUDED
