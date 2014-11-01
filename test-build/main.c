#include <stdio.h>
#include <uv.h>

int main(int argc,char*argv[]) {
    uv_loop_t loop={0};
    uv_loop_init(&loop);
    printf("Now quiting\n");
    uv_run(&loop,UV_RUN_DEFAULT);
    return 0;
}
