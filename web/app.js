import React from 'react';
import ReactDOM   from 'react-dom';

import Canvas from './js/Canvas'
import Umbrella from './js/Umbrella'
import UIAnimation from './js/UIAnimation';
import UI3D from './js/UI3D';

const LED_COUNT      = 30,
      STRIP_COUNT    = 8,
      UMBRELLA_COUNT = 3;

let canvas = new Canvas();

for (let i = 0; i < UMBRELLA_COUNT; i++) {

    let _x = LED_COUNT * i,
        _y = LED_COUNT * i;

    canvas.scene.add( new Umbrella( LED_COUNT, STRIP_COUNT, { x: _x, y: _y }) );

}

ReactDOM.render(<UIAnimation ledCount={ LED_COUNT } stripCount={ STRIP_COUNT }/>, document.getElementById('ui-animation'));
ReactDOM.render(<UI3D canvas={ canvas } />, document.getElementById('ui-3d'));
