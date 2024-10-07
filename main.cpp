#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>  // 다양한 기하학적 도형을 그리기 위해 GLUT 사용
#include <stdio.h>

const unsigned int WIN_W = 600;
const unsigned int WIN_H = 600;

// 탁자를 그리는 함수
void drawTable() {
    // 탁자 다리 4개
    glColor3f(0.55f, 0.27f, 0.07f); // 갈색 (나무색)
    glPushMatrix();
    glTranslatef(-0.4f, -0.5f, -0.4f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, -0.5f, -0.4f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, -0.5f, 0.4f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f, -0.5f, 0.4f);
    glScalef(0.1f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    // 탁자 상판
    glPushMatrix();
    glTranslatef(0.0f, -0.25f, 0.0f);
    glScalef(1.0f, 0.05f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();
}

// 탁자 위의 기하학적 물체들
void drawGeometricObjects() {
    // 구
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    glPushMatrix();
    // 구의 중심을 탁자 상판 위로 조금 올림
    glTranslatef(-0.2f, -0.25f + 0.1f, 0.0f); // 탁자 상판보다 약간 위로 이동 (반지름 고려)
    glutSolidSphere(0.1f, 50, 50); // 구를 그립니다.
    glPopMatrix();


    // 원뿔
    glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
    glPushMatrix();
    // 원뿔을 탁자 상판에 정확히 배치 (y 좌표를 상판 높이 -0.25에 원뿔의 밑면이 닿도록)
    glTranslatef(0.2f, -0.225f, 0.0f); // 탁자 상판과 동일한 y 값으로 설정
    glRotatef(-90, 1.0f, 0.0f, 0.0f); // 원뿔을 세우기 위해 x 축으로 90도 회전
    glutSolidCone(0.1f, 0.2f, 100, 100); // 원뿔 그리기
    glPopMatrix();
    
    // 큐브
    glColor3f(0.0f, 1.0f, 0.0f); // 녹색
    glPushMatrix();
    // 큐브를 탁자 상판에 딱 맞게 서 있도록 위치 조정 (상판 높이 -0.25에 큐브 높이의 절반을 더함)
    glTranslatef(0.0f, -0.25f + 0.05f, 0.3f); // y 좌표: 상판 높이 -0.25 + 큐브의 절반 크기 0.05
    glutSolidCube(0.1f); // 큐브 그리기
    glPopMatrix();

}

// 바닥을 그리는 함수
void drawFloor() {
    glColor3f(0.5f, 0.5f, 0.5f); // 회색 바닥
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -0.5f, -1.0f);
    glVertex3f(1.0f, -0.5f, -1.0f);
    glVertex3f(1.0f, -0.5f, 1.0f);
    glVertex3f(-1.0f, -0.5f, 1.0f);
    glEnd();
}

int main(void) {
    // GLFW 초기화
    if (!glfwInit()) {
        printf("GLFW initialization failed\n");
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "Table and Geometric Objects", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트 생성
    glfwMakeContextCurrent(window);

    // GLEW 초기화
    if (glewInit() != GLEW_OK) {
        printf("GLEW initialization failed!\n");
        return -1;
    }

    printf("GLEW initialized successfully!\n");
    printf("OpenGL version: %s\n", glGetString(GL_VERSION));
    printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    // 렌더링 루프
    while (!glfwWindowShouldClose(window)) {
        // 화면을 특정 색상으로 지우기 (배경색)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 바닥, 탁자, 기하학적 물체 그리기
        drawFloor();
        drawTable();
        drawGeometricObjects();

        // 버퍼 교체 및 이벤트 처리
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}

