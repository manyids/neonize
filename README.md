# neonize
Experimenting with ARM NEON assembly coding

Aim: Write simple functions

Further: optimize algorithms from state of the art papers on computer vision

To compile, use flag -mfpu=neon

Note: 

neonAsmXEdge:
An investigation into caching calculations of algorithms. In this example, the same calculation can yeild both an Edge detector and a Corner Detector.
Basically, we XOR each row with the next one, and each column with the next one. Given these two results, we can retrieve the edges by ORing the two and the corners by ANDing them.

Research goals:
The Viola-Jones algorithm basically combines weak classifiers to get a strong estimate. 
My goal is to combine weak high level inferences (at the cost of robustness, and the reward of speed) to gain a strong high level inference. 
For example, run many lightning fast but unreliable algorithms to segment images, and combine the outputs to produce one strong inference of segmentation. Stay loon, stay tuned :)

Documentation:
Forgive me for the lack of comments. I hope to automate entirely the commenting business since this thing is a very application specific. 
For example, a standard comment for each construct (loops, conditions, etc), then move hierarchically upward to get a comment for the entire function, then again up for the program, etc. Again, stay tuned...