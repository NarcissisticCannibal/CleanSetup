#include "Player.h"

Player::Player() {

}

void Player::Initialize(string _path, Vector2 _pos, float _friction, float _mass) {
	playerS = Sprite(_path, _pos);
	playerRB = Rigidbody();
	playerRB.Initialize(_friction, playerS.getPos(), playerS.getScale(), playerS.getRot(), playerS.getSize(), _mass);
}

void Player::Update() {
	playerS.Update();
	playerRB.Update();
}

void Player::Render() {
	playerS.Render();
	playerRB.Render(Vector3(1, 1, 1));
}