#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int Read(int fd, char *buf, int len, size_t offset) noexcept
{
    int totalRead = 0;
    int offset = 0;

    while (len > 0)
    {
        int n = TEMP_FAILURE_RETRY(pread64(fd, buf + offset, len, offset));

        if (n == 0)
        {
            totalRead += n;
            break;
        }

        if (n < 0)
        {
            return errno;
        }

        len -= n;
        totalRead += n;
        offset += n;
    }

    return totalRead;
}

int main()
{
    int fd = open("/home/rga/algorithms/main.cpp", O_RDONLY);
    if (fd < 0)
    {
        printf("open failed, errno: %d\n", errno);
        return -1;
    }

    char buf[8] = {0};

    int bytesRead;

    while ((bytesRead = Read(fd, buf, sizeof(buf) - 1)) > 0)
    {
        printf("%s", buf);
    }

    if (bytesRead < 0)
    {
        printf("Error reading file\n");
    }

    close(fd);
    return 0;
}
