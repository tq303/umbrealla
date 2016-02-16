import React from 'react';
import ReactDOM   from 'react-dom';

import Umbrella from './js/Umbrella';
import UIAnimation from './js/UIAnimation';
import UI3D from './js/UI3D';

const LED_COUNT   = 30,
      STRIP_COUNT = 8;

let umbrella = new Umbrella(LED_COUNT, STRIP_COUNT);

ReactDOM.render(<UIAnimation ledCount={ LED_COUNT } stripCount={ STRIP_COUNT }/>, document.getElementById('ui-animation'));
ReactDOM.render(<UI3D umbrella={ umbrella } />, document.getElementById('ui-3d'));
