#include <libchdr/coretypes.h>
#include <stdlib.h>
#include <assert.h>

core_file* core_falloc()
{
	core_file* result = calloc(1, sizeof(core_file));
	return result;
}

void core_ffree(core_file* file)
{
	free(file);
}

core_file* core_fopen(const char* path)
{
	//Not supported
	assert(0);
	return NULL;
}

void core_fclose(core_file* file)
{
	//Not supported
	assert(0);
}

UINT64 core_fread(core_file* file, void* buffer, UINT64 size)
{
	assert(file->read_function != NULL);
	return file->read_function(file->user_data, buffer, size);
}

void core_fseek(core_file* file, INT64 position, int whence)
{
	assert(file->seek_function != NULL);
	file->seek_function(file->user_data, position, whence);
}

UINT64 core_ftell(core_file* file)
{
	assert(file->tell_function != NULL);
	return file->tell_function(file->user_data);
}
