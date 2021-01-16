// Mechanics of writing bits to a buffer

/*This function writes bits to a buffer. 
This writes a gradient to a buffer, but by also 
using this function as a template - we can
play with algorithms that will draw pixels 
to the screen. 
*/




internal void
RenderWeirdGradient(sdl_offscreen_buffer Buffer, int BlueOffset, int GreenOffset)
{    
    
     //  Typical nested for loops that  iterate over a rectangular buffer (array)  
     //  Iterating over height (select each row, then move along the pixels in the row)
     
     
     // First though, we need to get at that memory. 
     
     // In the struct that we are going to pass to this rendering function 
     // the memory is just a void pointer - it doesn't actaully point to 
     // anything. So we are now recasting this pointer so it points at the 
     // beginning of the memory that we have. ie. It points at something. 
     
     // To gain more control over the pointer arith, we need to do something
     // additional. Why? When we increment a pointer, C takes into account the
     // size of the type the pointer points too. So if we have an 8 bit type, 
     // 1 movement of the pointer, will be multiplied by 8, so it moves to the
     // beginning of the next 8-bit value. We do not want that to happen, so we even though
     // Buffer.Memory contains 32-byte values for each pixel, we DO NOT want to keep
     // skipping those 4 bytes, we want to manipulate each byte properly.
     // So we are going to be moving the pointer by 8-bits. So one pixel
     // will be represented by 4 movements of the pointer 
     
     
    uint8 *Row = (uint8 *)Buffer.Memory; 
           
   
    
         
           
    for(int Y = 0; 
        Y < Buffer.Height;
        ++Y)
        
        //Lets iterate over pixels
        
    {
        uint32 *Pixel = (uint32 *)Row; // Pointer moves every 32 bits..
        
        for(int X = 0; 
            X < Buffer.Width;
            ++X)
        {
            uint8 Blue = (X + BlueOffset);
            uint8 Green = (Y + GreenOffset);
            
            *Pixel++ = ((Green << 8) | Blue);
        }

        Row += Buffer.Pitch; // Move to next row
    }
}
