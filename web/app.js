import React from 'react';
import ReactDOM   from 'react-dom';

import Umbrella from './js/Umbrella';
import UI from './js/UI';

const LED_COUNT   = 30,
      STRIP_COUNT = 8;

let umbrella = new Umbrella(LED_COUNT, STRIP_COUNT);

ReactDOM.render(<UI ledCount={ LED_COUNT } stripCount={ STRIP_COUNT }/>, document.getElementById('ui'));
