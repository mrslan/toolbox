#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <jerror.h>

using namespace std;

int load_texture (const char * filename,
        unsigned char * dest,
        const int format,
        const unsigned int size)
{
    FILE *fd;
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    unsigned char * line;

    cinfo.err = jpeg_std_error (&jerr);
    jpeg_create_decompress (&cinfo);

    if (0 == (fd = fopen(filename, "rb")))
    {
        return 1;
    }

    jpeg_stdio_src (&cinfo, fd);
    jpeg_read_header (&cinfo, TRUE);
//    if ((cinfo.image_width != size) || (cinfo.image_height != size))
//    {
//        return 2;
//    }

    jpeg_start_decompress (&cinfo);

    while (cinfo.output_scanline < cinfo.output_height)
    {
        line = dest + 3 * size * cinfo.output_scanline;
        jpeg_read_scanlines (&cinfo, &line, 1);
    }
    jpeg_finish_decompress (&cinfo);
    jpeg_destroy_decompress (&cinfo);
    return 0;
}
