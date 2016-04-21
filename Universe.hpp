#ifndef PS4_UNIVERSE_HPP
#define PS4_UNIVERSE_HPP

#include <SFML/Graphics.hpp>

namespace Universe {

class SpaceObject : public sf::Drawable {
 public:
  SpaceObject();
  SpaceObject(sf::Vector2f location, sf::Vector2u velocity, double mass);
  ~SpaceObject();
  const sf::Vector2f &getLocation() const;
  void setLocation(const sf::Vector2f &location);
  const sf::Vector2u &getVelocity() const;
  void setVelocity(const sf::Vector2u &velocity);
  double getMass() const;
  void setMass(double mass);
 private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::Vector2f location_;
  sf::Vector2u velocity_;
  double       mass_;
};

class Start : public SpaceObject {
 public:
  Start();
  Start(sf::Vector2f location, sf::Vector2u velocity, double mass);
  ~Start();
 private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::Vector2f positionGenerator();
  float radiusGenerator();
  sf::CircleShape shape_;

};

}  // namespace Universe

#endif //PS4_UNIVERSE_HPP
