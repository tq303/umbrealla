import React from 'react';
import ReactDOM   from 'react-dom';

import Canvas from './js/Canvas'
import Umbrella from './js/Umbrella'
import Animator from './js/Animator'
import UIAnimation from './js/UIAnimation';
import UI3D from './js/UI3D';

const LED_COUNT      = 30,
      STRIP_COUNT    = 8,
      UMBRELLA_COUNT = 3;

let canvas = new Canvas(),
    umbrellas = [];

// create umbrellas and add to canvas
for (let i = 0; i < UMBRELLA_COUNT; i++) {

    let _x, _y, _z;

    if (i === 0) {
        _x = 0;
        _y = LED_COUNT - 8;
        _z = 0;
    } else {
        _x = (i % 2 === 1) ? -LED_COUNT : LED_COUNT;
        _y = -LED_COUNT;
        _z = (i % 2 === 1) ? -1 : 1;
    }

    umbrellas[i] = new Umbrella( LED_COUNT, STRIP_COUNT, { x: _x, y: _y });
    umbrellas[i].rotation.z = _z;

    canvas.scene.add( umbrellas[i] );

}

let animator = new Animator();

animator.umbrellas = umbrellas;

ReactDOM.render(<UIAnimation frames={ animator.frames } ledCount={ LED_COUNT } stripCount={ STRIP_COUNT }/>, document.getElementById('ui-animation'));
// ReactDOM.render(<UI3D canvas={ canvas } />, document.getElementById('ui-3d'));
