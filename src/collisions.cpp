// bool intersection_hitsphere(glm::vec4 pos,glm::vec4 aim, glm::vec4 model_center, float far){
//     float r = 10;
//     float A = norm(aim) * norm(aim);
//     float B = 2 * dot(aim, (pos - model_center));
//     float C = norm(pos - model_center) * norm(pos - model_center) - r;

//     float t;
//     if(0 == t*t*A + t*B + C){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// bool intersection_raio(glm::vec4 obj_a, glm::vec4 obj_b, float raio_a, float raio_b){
//     if(norm(obj_a - obj_b) <= (raio_a + raio_b)){
//         return true;
//     }
//     else{
//         return false;
//     }

bool CheckCollision(const glm::vec3 bbox1min, const glm::vec3 bbox1max, const glm::vec3 bbox2min, const glm::vec3 bbox2max) {

    // Collision x-axis?
    bool collisionX = bbox1max.x >= bbox2min.x && bbox2max.x >= bbox1min.x;
    // Collision y-axis?
    bool collisionY = bbox1max.y >= bbox2min.y && bbox2max.y >= bbox1min.y;
    // Collision z-axis?
    bool collisionZ = bbox1max.z >= bbox2min.z && bbox2max.z >= bbox1min.z;

    // Collisions occur only if there's overlap along all three axes
    return collisionX && collisionY && collisionZ;
}

bool CheckSphereCollision(const glm::vec3 bbox1min, const glm::vec3 bbox1max, const glm::vec3 bbox2min, const glm::vec3 bbox2max) {
    float meanx1 = (bbox1min.x + bbox1max.x)/2;
    float meany1 = (bbox1min.y + bbox1max.y)/2;
    float meanz1 = (bbox1min.z + bbox1max.z)/2;

    float meanx2 = (bbox2min.x + bbox2max.x)/2;
    float meany2 = (bbox2min.y + bbox2max.y)/2;
    float meanz2 = (bbox2min.z + bbox2max.z)/2;

    glm::vec3 center_sphere1 = glm::vec3(meanx1, meany1, meanz1);
    glm::vec3 center_sphere2 = glm::vec3(meanx2, meany2, meanz2);

    float radius1 = std::max(bbox1max.x - bbox1min.x, bbox1max.y - bbox1min.y, bbox1max.z - bbox1min.z);
    float radius2 = std::max(bbox2max.x - bbox2min.x, bbox2max.y - bbox2min.y, bbox2max.z - bbox2min.z);

    if(center_sphere1.x - center_sphere2.x <= radius1 + radius2 && center_sphere1.y - center_sphere2.y <= radius1 + radius2 && center_sphere1.z - center_sphere2.z <= radius1 + radius2){
        return true;
    }
    else{
        return false;
    }
}

bool CheckCillinderCollision(const glm::vec3 bbox1min, const glm::vec3 bbox1max, const glm::vec3 bbox2min, const glm::vec3 bbox2max) {
    float meanx1 = (bbox1min.x + bbox1max.x)/2;
    float meany1 = (bbox1min.y + bbox1max.y)/2;
    float meanz1 = (bbox1min.z + bbox1max.z)/2;

    float meanx2 = (bbox2min.x + bbox2max.x)/2;
    float meany2 = (bbox2min.y + bbox2max.y)/2;
    float meanz2 = (bbox2min.z + bbox2max.z)/2;

    glm::vec3 center_cillinder1 = glm::vec3(meanx1, meany1, meanz1);
    glm::vec3 center_cillinder2 = glm::vec3(meanx2, meany2, meanz2);

    float radius1 = std::max(bbox1max.x - bbox1min.x, bbox1max.z - bbox1min.z);
    float radius2 = std::max(bbox2max.x - bbox2min.x, bbox2max.z - bbox2min.z);

    if(center_cillinder1.x - center_cillinder2.x <= radius1 + radius2 && center_cillinder1.y - center_cillinder2.y <= bbox1max.y - bbox1min.y + bbox2max.y - bbox2min.y && center_cillinder1.z - center_cillinder2.z <= radius1 + radius2){
        return true;
    }
    else{
        return false;
    }
}

// bool spherical_collision(glm::vec3 pos1, glm::vec3 pos2, float r1, float r2){
//     if(norm(pos1 - pos2) <= (r1 + r2)){
//         return true;
//     }
//     else{
//         return false;
//     }
// }