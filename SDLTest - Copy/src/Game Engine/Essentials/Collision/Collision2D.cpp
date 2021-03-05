#include "../Collision/Collision2D.h"

bool Collision2D::AABB(const SDL_Rect& recA, const SDL_Rect& recB){
    return (recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x &&
            recA.y + recA.h >= recB.y && recB.y + recB.h >= recA.y);
}

bool Collision2D::AABB(const BoxCollider2D& colA, const BoxCollider2D& colB){
    return AABB(colA.box, colB.box);
}
