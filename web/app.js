import Canvas from './js/Canvas'
import Umbrella from './js/Umbrella'
import Animator from './js/Animator'

window.LED_COUNT      = 30;
window.STRIP_COUNT    = 8;
window.UMBRELLA_COUNT = 3;

let width  = 720,
    height = ( width / 16 ) * 9;

let canvas = new Canvas( width, height, 25 ),
    umbrellas = [];

// add single umbrella
umbrellas[0] = new Umbrella({ x: 0, y: 0 });
canvas.scene.add( umbrellas[0] );

let animator = new Animator( umbrellas );
