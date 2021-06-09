#pragma once

#define DEF_SNAKE_LONG 100
char strGameBack[20][48] = { "███████████████████████",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"█                                          █",
							"███████████████████████" };

//蛇数组
int arrSnake[DEF_SNAKE_LONG][3] = { 0 };
//方向
enum { to_up = -1, to_down = 1, to_lift = -2, to_right = 2 };

//蛇方向
int g_nSnakedir = to_right;