// Destructor (de-Allocate memory to prevent memory leak)

for (int i = 0; i < HEIGHT; ++i) 
{
    for (int j = 0; j < WIDTH; ++j)
        delete [] p2DArray[i][j];
            delete [] p2DArray[i];
}
delete [] p2DArray;

*/

