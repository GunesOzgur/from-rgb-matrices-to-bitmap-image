/* matrix2bmp-2.c
 *
 * This code creates a bitmap image according
 * to 3 channel (RGB) matrices.
 *
 * Last modified on March 01, 2021
 *
 * by Freeman Sun
*/

#include <stdint.h>
#include <stdio.h>
#include <windows.h>

// Global Variables for BMP Chunks
uint16_t bmp_header = 0x4D42; // Bytes 0-1
uint64_t bmp_total_size; // Bytes 2-9
uint32_t bmp_data_adress = 0x00000036; // Bytes 10-13
uint32_t bmp_CoreHeader_size = 0x00000028; // Bytes 14-17
uint32_t bmp_width; // Bytes 18-21
uint32_t bmp_height; // Bytes 22-25
uint16_t bmp_color_planes = 0x0001; // Bytes 26-27
uint16_t bmp_bit_per_pixel = 0x0018; // Bytes 28-29
uint32_t bmp_compression_method = 0x00000000; // Bytes 30-33
uint32_t bmp_data_size; // Bytes 34-37
uint32_t bmp_horizontal_resolution = 0x00000000; // Bytes 38-41
uint32_t bmp_vertical_resolution = 0x00000000; // Bytes 42-45
uint32_t bmp_num_of_colors_in_palette = 0x00000000; // Bytes 46-49
uint32_t bmp_num_of_important_colors = 0x00000000; // Bytes 50-54

// Other Global Variables
uint32_t width, height;

int mat2bmp(
	uint8_t R_m[height][width],
	uint8_t G_m[height][width],
	uint8_t B_m[height][width],
	char* bmpName)
{
	// Transfer the data from GB matrices into the BMP file
	
	// Arguments:
	// R_m -> RED Channel Matrix
	// G_m -> GREEN Channel Matrix
	// B_m -> BLUE Channel Matrix
	// bmpName -> name for the BMP that will be created
	
	// Set variable values
	bmp_width = width;
	bmp_height = height;
	bmp_data_size = ((width*3)+(width%4))*height;
	bmp_total_size = bmp_data_size + bmp_data_adress;
	
	FILE *fPtr;
	
	if( (fPtr = fopen(bmpName, "wb")) == NULL ) {

		MessageBox(0, bmpName, "Not opened!",
			MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
		
		return -1;
	}
	
	uint8_t Byte;
	uint64_t longInt;
	
	// Print bmp_header
	longInt = bmp_header;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 0
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 1
	
	// Print bmp_total_size
	longInt = bmp_total_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 2
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 3
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 4
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 5
	Byte = longInt>>32;
	fprintf(fPtr, "%c", Byte); // Byte 6
	Byte = longInt>>40;
	fprintf(fPtr, "%c", Byte); // Byte 7
	Byte = longInt>>48;
	fprintf(fPtr, "%c", Byte); // Byte 8
	Byte = longInt>>56;
	fprintf(fPtr, "%c", Byte); // Byte 9
	
	// Print bmp_data_adress
	longInt = bmp_data_adress;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 10
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 11
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 12
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 13
	
	// Print bmp_CoreHeader_size
	longInt = bmp_CoreHeader_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 14
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 15
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 16
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 17
	
	// Print bmp_width
	longInt = bmp_width;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 18
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 19
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 20
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 21
	
	// Print bmp_height
	longInt = bmp_height;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 22
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 23
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 24
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 25
	
	// Print bmp_color_planes
	longInt = bmp_color_planes;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 26
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 27
	
	// Print bmp_bit_per_pixel
	longInt = bmp_bit_per_pixel;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 28
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 29
	
	// Print bmp_compression_method
	longInt = bmp_compression_method;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 30
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 31
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 32
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 33
	
	// Print bmp_data_size
	longInt = bmp_data_size;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 34
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 35
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 36
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 37
	
	// Print bmp_horizontal_resolution
	longInt = bmp_horizontal_resolution;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 38
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 39
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 40
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 41
	
	// Print bmp_vertical_resolution
	longInt = bmp_vertical_resolution;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 42
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 43
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 44
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 45
	
	// Print bmp_num_of_colors_in_palette
	longInt = bmp_num_of_colors_in_palette;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 46
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 47
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 48
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 49
	
	// Print bmp_num_of_important_colors
	longInt = bmp_num_of_important_colors;
	Byte = longInt;
	fprintf(fPtr, "%c", Byte); // Byte 50
	Byte = longInt>>8;
	fprintf(fPtr, "%c", Byte); // Byte 51
	Byte = longInt>>16;
	fprintf(fPtr, "%c", Byte); // Byte 52
	Byte = longInt>>24;
	fprintf(fPtr, "%c", Byte); // Byte 53
	
	printf("width: %d\n", bmp_width);
	printf("height: %d\n", bmp_height);
	printf("data adress: %d\n", bmp_data_adress);
	printf("data size: %d\n", bmp_data_size);
	
	// Print actual data
	uint32_t x,y;
	for(y = 1; y <= bmp_height; y++) {
		
		for(x = 0; x < bmp_width; x++) {
			
			fprintf(fPtr, "%c", B_m[bmp_height-y][x]);
			fprintf(fPtr, "%c", G_m[bmp_height-y][x]);
			fprintf(fPtr, "%c", R_m[bmp_height-y][x]);		
		}
		
		for(x = 0; x < (bmp_width%4); x++) {
			
			fprintf(fPtr, "%c", 0);	
		}
	}
	
	fclose(fPtr);
	return 0;
} // mat2bmp()

int main(int argc, char** argv)
{
	width = 13;
	height = 7;
	
	uint8_t red[7][13] = {
		{255, 255, 255, 255, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{255, 255, 255, 255, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000} };
	
	uint8_t green[7][13] = {
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 255, 255, 255, 255, 000, 000, 255, 255, 000},
		{000, 000, 255, 255, 255, 255, 255, 255, 000, 000, 255, 255, 000},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000} };
	
	uint8_t blue[7][13] = {
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000},
		{255, 255, 000, 000, 255, 255, 255, 255, 255, 255, 000, 000, 255},
		{255, 255, 000, 000, 255, 255, 255, 255, 255, 255, 000, 000, 255},
		{000, 000, 255, 255, 000, 000, 255, 255, 000, 000, 255, 255, 000} };
	
	mat2bmp(red, green, blue, argv[1]);
	
	return 0;
} // main()