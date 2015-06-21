#include "PlayerBullet.h"
#include "Graphics.h"
#include "Collision.h"
#include "cinder\app\AppNative.h"


using namespace ci;
using namespace ci::app;
using PlayerType = Player::Type;

PlayerBullet::PlayerBullet(const Vec3f& pos, const Vec3f& direction, const ColorA& color, const PlayerType type) :
direction(direction)
{
	this->color = color;
	this->pos = pos;

	std::unordered_map<PlayerType,std::function<void()>> collision_map = 
	{
		{
			PlayerType::ONE,
			[this](){

				for(auto& player: Player::getVector())
				{
					if (player->getType() == Player::Type::ONE)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if(player->getState() != Player::State::DOWN){
						if(!player->isHit())
						{
							if (isHitSphereAndSphere(this->pos, 0.2f, player->getPos(), 0.7f))
							{
								player->hit();
								destory();
							}
						}
					}
				}
			}
		},
		{
			PlayerType::TWO,
			[this](){

				for (auto& player : Player::getVector())
				{
					if (player->getType() == Player::Type::TWO)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != Player::State::DOWN){
						if (!player->isHit())
						{
							if (isHitSphereAndSphere(this->pos, 0.2f, player->getPos(), 0.7f))
							{
								player->hit();
								destory();
							}
						}
					}
				}
			}
		},
		{
			PlayerType::THREE,
			[this](){

				for (auto& player : Player::getVector())
				{
					if (player->getType() == Player::Type::THREE)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != Player::State::DOWN){
						if (!player->isHit())
						{
							if (isHitSphereAndSphere(this->pos, 0.2f, player->getPos(), 0.7f))
							{
								player->hit();
								destory();
							}
						}
					}
				}
			}
		},
		{
			PlayerType::FOUR,
			[this](){

				for (auto& player : Player::getVector())
				{
					if (player->getType() == Player::Type::FOUR)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != Player::State::DOWN){
						if (!player->isHit())
						{
							if (isHitSphereAndSphere(this->pos, 0.2f, player->getPos(), 0.7f))
							{
								player->hit();
								destory();
							}
						}
					}
				}
			}
		}
	};

	collider = collision_map.find(type)->second;

}

void PlayerBullet::update()
{
	pos.x += direction.x *0.4f;
	pos.z += direction.z *0.4f;
	if(isHitSphereAndSphereBack(Vec3f::zero(),100,pos,0.2f))
	{
		destory();
	}
	collider();
}

void PlayerBullet::draw()
{
	g3d::drawSphere(pos, 0.2f,color);
}