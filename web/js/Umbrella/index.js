import THREE from 'three';

class Umbrella {
    constructor( ledCount, stripCount ) {

        // setup variables
        this.ledCount    = ledCount;
        this.stripCount  = stripCount;
        this.ledDistance = 1;

        this.cameraRotationX = 90;
        this.cameraRotationY = 90;
        this.cameraRotationZ = 90;
        this.cameraZoom      = 75;

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
        this.moveCameraUpDwn(45);
        this.moveCameraLeftRight(0);
    }
    loop() {
        requestAnimationFrame( () => this.loop() );
        this.renderer.render( this.scene, this.camera );
    }
    createArm( angle ) {

        let arm = new THREE.Geometry(),
            x   = Math.cos(this.radians(angle)),
            y   = Math.sin(this.radians(angle));

        // loop each led and place in x,y,z axis
        for (let i = 0; i <= this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ) + 45,
                _z     = Math.cos(this.radians(_angle)) * ( this.ledDistance * i );

            arm.vertices.push(new THREE.Vector3(_x, _y, _z));
        }

        return arm;
    }
    moveCameraUpDwn( amount ) {

        this.cameraRotationY = this.ensureAngle( amount, this.cameraRotationY );
        this.cameraRotationZ = this.ensureAngle( amount, this.cameraRotationZ );

        let _y = Math.cos(this.radians(this.cameraRotationY)) * this.cameraZoom,
            _z = Math.sin(this.radians(this.cameraRotationY)) * this.cameraZoom;

        this.camera.position.y = _y;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    moveCameraLeftRight( amount ) {

        this.cameraRotationX = this.ensureAngle( amount, this.cameraRotationX );
        this.cameraRotationZ = this.ensureAngle( amount, this.cameraRotationZ );

        let _x = Math.cos(this.radians(this.cameraRotationX)) * this.cameraZoom,
            _z = Math.sin(this.radians(this.cameraRotationX)) * this.cameraZoom;

        this.camera.position.x = _x;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    setCameraZoom( angle ) {
        this.cameraZoom = angle;
        this.moveCameraUpDwn(0);
        this.moveCameraLeftRight(0);
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
    ensureAngle( amount, variable ) {
        if (variable + amount >= 360) {
            return 0;
        }

        return ( variable + amount );
    }
}

export default Umbrella;
