#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavfilter/avfilter.h>
#include <libavutil/dict.h>

int main(int argc,char *argv[])
{

    int64_t secs,us ;

    av_register_all();

    AVFormatContext *pFormatCtx = NULL;

    if(avformat_open_input(&pFormatCtx,argv[1],NULL,NULL))
        return -1;
    if(avformat_find_stream_info(pFormatCtx,NULL)<0)
        return -1;

    secs=pFormatCtx->duration/AV_TIME_BASE;
    us=pFormatCtx->duration%AV_TIME_BASE;

    printf("%02ld:%02ld:%02ld\n",secs/3600,(secs%3600)/60,(secs%3600)%60);
    exit(0);
}
