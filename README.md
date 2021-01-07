# opus1

Video game development repo. 

SDL Boilerplate code has been derived from Molly Rocket's Handmade Hero's first few streams with adaptions/ports to linux from the website Handmade Penguin.
The stream makes use of the Win32 API, so in Linux we need to use SDL. No worries there though, as SDL provides the same functionality, albeit in a different way, 
hence the need for Handmade Penguin's explanations of the differences. 

The Boilerplate code sets up SDL to window manage, take care of event input (Keyboard, Mouse etc) and, most importantly, gives us access to a back/double buffer 
so one can have total and complete control over the rendering.  
