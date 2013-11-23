#ifndef MMAPPED_H
#define MMAPPED_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include "common.h"

#define FILENAME "clients"
#define FILESIZE (CLIENTSMAX * sizeof(client))

void initMPD();

#endif
