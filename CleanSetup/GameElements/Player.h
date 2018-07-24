#pragma once

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physix/Rigidbody.h"
#include "../Engine/Math/Vector2.h"

class Player {
public:
	
	Sprite playerS;
	Rigidbody playerRB;

	Player();
	
	void Initialize(string _path, Vector2 _pos, float _friction, float _mass);
	void Update();
	void Render();

private:

};
