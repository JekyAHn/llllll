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

    // ���� ������ ��ǥ �̵� �Լ�
    Vertex MoveVertex(Vertex point, Vector meter) {
        Vertex newPoint;
        newPoint.x = point.x + meter.x_meter;
        newPoint.y = point.y + meter.y_meter;
        return newPoint;
    }

    // ���� ������ �ð� ���� ȸ�� �Լ�
    Vertex RotateVertex(Vertex point, float angle_degree) {
        float angle_radians = angle_degree * 3.14159265358979323846 / 180.0; // ������ �������� ��ȯ
        Vertex newPoint;
        newPoint.x = point.x * cos(angle_radians) - point.y * sin(angle_radians);
        newPoint.y = point.x * sin(angle_radians) + point.y * cos(angle_radians);
        return newPoint;
    }

    // ���� ������ ��ǥ ���� ���� �Լ�
    Vertex ScaleVertex(Vertex point, Vector meter) {
        Vertex newPoint;
        newPoint.x = point.x * meter.x_meter;
        newPoint.y = point.y * meter.y_meter;
        return newPoint;
    }
};

