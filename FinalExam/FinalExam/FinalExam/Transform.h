#pragma once
#include <cmath>

namespace Transform {

    struct Vertex {
        float x;
        float y;
    };

    struct Vector {
        float x_meter;
        float y_meter;
    };

    // 미터 단위로 좌표 이동 함수
    Vertex MoveVertex(Vertex point, Vector meter) {
        Vertex newPoint;
        newPoint.x = point.x + meter.x_meter;
        newPoint.y = point.y + meter.y_meter;
        return newPoint;
    }

    // 각도 단위로 시계 방향 회전 함수
    Vertex RotateVertex(Vertex point, float angle_degree) {
        float angle_radians = angle_degree * 3.14159265358979323846 / 180.0; // 각도를 라디안으로 변환
        Vertex newPoint;
        newPoint.x = point.x * cos(angle_radians) - point.y * sin(angle_radians);
        newPoint.y = point.x * sin(angle_radians) + point.y * cos(angle_radians);
        return newPoint;
    }

    // 미터 단위로 좌표 배율 조정 함수
    Vertex ScaleVertex(Vertex point, Vector meter) {
        Vertex newPoint;
        newPoint.x = point.x * meter.x_meter;
        newPoint.y = point.y * meter.y_meter;
        return newPoint;
    }
};

