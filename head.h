#pragma once

#define DEF_SNAKE_LONG 100
char strGameBack[20][48] = { "����������������������������������������������",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"��                                          ��",
							"����������������������������������������������" };

//������
int arrSnake[DEF_SNAKE_LONG][3] = { 0 };
//����
enum { to_up = -1, to_down = 1, to_lift = -2, to_right = 2 };

//�߷���
int g_nSnakedir = to_right;