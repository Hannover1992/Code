
#!/bin/bash

function bluetooth_control() {
    device_mac=$1
    action=$2

    case "$action" in
        --on)
            sudo bluetoothctl <<EOF
power on
connect $device_mac
exit
EOF
            ;;
        --off)
            sudo bluetoothctl <<EOF
disconnect $device_mac
exit
EOF
            ;;
        --help)
            echo "Usage: ${0##*/} --dev {device} {--on|--off|--help}"
            echo "Commands:"
            echo "--on    Turn on Bluetooth and connect to the device"
            echo "--off   Disconnect from the Bluetooth device"
            echo "--help  Display this help message"
            ;;
        *)
            echo "Invalid argument. Please use '--on', '--off' or '--help'."
            echo "Use '${0##*/} --help' for more information."
            exit 1
            ;;
    esac
}
