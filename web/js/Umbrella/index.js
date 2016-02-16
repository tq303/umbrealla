import THREE from 'three';

class Umbrella {
    constructor( ledCount, stripCount ) {

        // setup variables
        this.ledCount    = ledCount;
        this.stripCount  = stripCount;
        this.ledDistance = 1;

        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 100;

        // material & geometry
        this.material = new THREE.LineBasicMaterial({
            color: 0xffffff
        });

        // build arms and rotate around center axis
        this.arms = [];

        for (let i = 0; i < this.stripCount; i++) {

            let geometry = this.createArm( (360 / this.stripCount) * i );

            this.arms[i] = new THREE.Line( geometry, this.material );

            // add geometry to scene
            this.scene.add( this.arms[i] );

        }

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        this.loop();
    }
    loop() {
        requestAnimationFrame( () => this.loop() );
        this.renderer.render( this.scene, this.camera );
    }
    createArm( angle ) {

        let arm = new THREE.Geometry(),
            x   = Math.cos(this.radians(angle)),
            y   = Math.sin(this.radians(angle));

        for (let i = 0; i <= this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ),
                _z     = Math.cos(this.radians(_angle)) * this.ledDistance;

            arm.vertices.push(new THREE.Vector3(_x, _y, _z));
        }

        return arm;
    }
    moveCameraUpDwn( amount ) {
        this.moveCamera( 'y', amount );
    }
    moveCameraLeftRight( amount ) {
        this.moveCamera( 'x', amount );
    }
    moveCamera ( axis, amount ) {
        this.camera.position[ axis ] += amount;
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
}

export default Umbrella;
