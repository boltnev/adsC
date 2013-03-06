#ifndef DATALOADER_H_INCLUDED
#define DATALOADER_H_INCLUDED

long *dataload();
void load_from_file(const char filename[], long data[], int *len);

size_t loadFilePart(const char filename[],
                          long data[],
                        size_t *count,
                        size_t startPos);
#endif // DATALOADER_H_INCLUDED
