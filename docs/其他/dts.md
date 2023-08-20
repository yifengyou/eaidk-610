# dts

```
/dts-v1/;

/ {
	compatible = "rockchip,rk3399-eaidk-mipi\0rockchip,rk3399";
	interrupt-parent = <0x01>;
	#address-cells = <0x02>;
	#size-cells = <0x02>;

	ddr_timing {
		compatible = "rockchip,ddr-timing";
		ddr3_speed_bin = <0x15>;
		pd_idle = <0x00>;
		sr_idle = <0x00>;
		sr_mc_gate_idle = <0x00>;
		srpd_lite_idle = <0x00>;
		standby_idle = <0x00>;
		auto_lp_dis_freq = <0x29a>;
		ddr3_dll_dis_freq = <0x12c>;
		phy_dll_dis_freq = <0x104>;
		ddr3_odt_dis_freq = <0x29a>;
		ddr3_drv = <0x28>;
		ddr3_odt = <0x78>;
		phy_ddr3_ca_drv = <0x28>;
		phy_ddr3_dq_drv = <0x28>;
		phy_ddr3_odt = <0xf0>;
		lpddr3_odt_dis_freq = <0x29a>;
		lpddr3_drv = <0x22>;
		lpddr3_odt = <0xf0>;
		phy_lpddr3_ca_drv = <0x22>;
		phy_lpddr3_dq_drv = <0x22>;
		phy_lpddr3_odt = <0xf0>;
		lpddr4_odt_dis_freq = <0x320>;
		lpddr4_drv = <0xf0>;
		lpddr4_dq_odt = <0x28>;
		lpddr4_ca_odt = <0x00>;
		phy_lpddr4_ca_drv = <0x28>;
		phy_lpddr4_ck_cs_drv = <0x28>;
		phy_lpddr4_dq_drv = <0x3c>;
		phy_lpddr4_odt = <0x28>;
		phandle = <0x92>;
	};

	aliases {
		i2c0 = "/i2c@ff3c0000";
		i2c1 = "/i2c@ff110000";
		i2c2 = "/i2c@ff120000";
		i2c3 = "/i2c@ff130000";
		i2c4 = "/i2c@ff3d0000";
		i2c5 = "/i2c@ff140000";
		i2c6 = "/i2c@ff150000";
		i2c7 = "/i2c@ff160000";
		i2c8 = "/i2c@ff3e0000";
		serial0 = "/serial@ff180000";
		serial1 = "/serial@ff190000";
		serial2 = "/serial@ff1a0000";
		serial3 = "/serial@ff1b0000";
		serial4 = "/serial@ff370000";
		dsi0 = "/dsi@ff960000";
		dsi1 = "/dsi@ff968000";
	};

	cpus {
		#address-cells = <0x02>;
		#size-cells = <0x00>;

		cpu-map {

			cluster0 {

				core0 {
					cpu = <0x02>;
				};

				core1 {
					cpu = <0x03>;
				};

				core2 {
					cpu = <0x04>;
				};

				core3 {
					cpu = <0x05>;
				};
			};

			cluster1 {

				core0 {
					cpu = <0x06>;
				};

				core1 {
					cpu = <0x07>;
				};
			};
		};

		cpu@0 {
			device_type = "cpu";
			compatible = "arm,cortex-a53\0arm,armv8";
			reg = <0x00 0x00>;
			enable-method = "psci";
			#cooling-cells = <0x02>;
			dynamic-power-coefficient = <0x64>;
			clocks = <0x08 0x08>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0b>;
			sched-energy-costs = <0x0c 0x0d>;
			cpu-supply = <0x0e>;
			phandle = <0x02>;
		};

		cpu@1 {
			device_type = "cpu";
			compatible = "arm,cortex-a53\0arm,armv8";
			reg = <0x00 0x01>;
			enable-method = "psci";
			clocks = <0x08 0x08>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0b>;
			sched-energy-costs = <0x0c 0x0d>;
			cpu-supply = <0x0e>;
			phandle = <0x03>;
		};

		cpu@2 {
			device_type = "cpu";
			compatible = "arm,cortex-a53\0arm,armv8";
			reg = <0x00 0x02>;
			enable-method = "psci";
			clocks = <0x08 0x08>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0b>;
			sched-energy-costs = <0x0c 0x0d>;
			cpu-supply = <0x0e>;
			phandle = <0x04>;
		};

		cpu@3 {
			device_type = "cpu";
			compatible = "arm,cortex-a53\0arm,armv8";
			reg = <0x00 0x03>;
			enable-method = "psci";
			clocks = <0x08 0x08>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0b>;
			sched-energy-costs = <0x0c 0x0d>;
			cpu-supply = <0x0e>;
			phandle = <0x05>;
		};

		cpu@100 {
			device_type = "cpu";
			compatible = "arm,cortex-a72\0arm,armv8";
			reg = <0x00 0x100>;
			enable-method = "psci";
			#cooling-cells = <0x02>;
			dynamic-power-coefficient = <0x1b4>;
			clocks = <0x08 0x09>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0f>;
			sched-energy-costs = <0x10 0x11>;
			cpu-supply = <0x12>;
			phandle = <0x06>;
		};

		cpu@101 {
			device_type = "cpu";
			compatible = "arm,cortex-a72\0arm,armv8";
			reg = <0x00 0x101>;
			enable-method = "psci";
			clocks = <0x08 0x09>;
			cpu-idle-states = <0x09 0x0a>;
			operating-points-v2 = <0x0f>;
			sched-energy-costs = <0x10 0x11>;
			cpu-supply = <0x12>;
			phandle = <0x07>;
		};

		idle-states {
			entry-method = "psci";

			cpu-sleep {
				compatible = "arm,idle-state";
				local-timer-stop;
				arm,psci-suspend-param = <0x10000>;
				entry-latency-us = <0x78>;
				exit-latency-us = <0xfa>;
				min-residency-us = <0x384>;
				phandle = <0x09>;
			};

			cluster-sleep {
				compatible = "arm,idle-state";
				local-timer-stop;
				arm,psci-suspend-param = <0x1010000>;
				entry-latency-us = <0x190>;
				exit-latency-us = <0x1f4>;
				min-residency-us = <0x7d0>;
				phandle = <0x0a>;
			};
		};
	};

	pmu_a53 {
		compatible = "arm,cortex-a53-pmu";
		interrupts = <0x01 0x07 0x08 0x13>;
	};

	pmu_a72 {
		compatible = "arm,cortex-a72-pmu";
		interrupts = <0x01 0x07 0x08 0x14>;
	};

	psci {
		compatible = "arm,psci-1.0";
		method = "smc";
	};

	timer {
		compatible = "arm,armv8-timer";
		interrupts = <0x01 0x0d 0x08 0x00 0x01 0x0e 0x08 0x00 0x01 0x0b 0x08 0x00 0x01 0x0a 0x08 0x00>;
	};

	xin24m {
		compatible = "fixed-clock";
		clock-frequency = <0x16e3600>;
		clock-output-names = "xin24m";
		#clock-cells = <0x00>;
	};

	dummy_cpll {
		compatible = "fixed-clock";
		clock-frequency = <0x00>;
		clock-output-names = "dummy_cpll";
		#clock-cells = <0x00>;
	};

	dummy_vpll {
		compatible = "fixed-clock";
		clock-frequency = <0x00>;
		clock-output-names = "dummy_vpll";
		#clock-cells = <0x00>;
	};

	amba {
		compatible = "arm,amba-bus";
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;

		dma-controller@ff6d0000 {
			compatible = "arm,pl330\0arm,primecell";
			reg = <0x00 0xff6d0000 0x00 0x4000>;
			interrupts = <0x00 0x05 0x04 0x00 0x00 0x06 0x04 0x00>;
			#dma-cells = <0x01>;
			clocks = <0x08 0xd3>;
			clock-names = "apb_pclk";
			peripherals-req-type-burst;
			phandle = <0x9a>;
		};

		dma-controller@ff6e0000 {
			compatible = "arm,pl330\0arm,primecell";
			reg = <0x00 0xff6e0000 0x00 0x4000>;
			interrupts = <0x00 0x07 0x04 0x00 0x00 0x08 0x04 0x00>;
			#dma-cells = <0x01>;
			clocks = <0x08 0xd4>;
			clock-names = "apb_pclk";
			peripherals-req-type-burst;
		};
	};

	ethernet@fe300000 {
		compatible = "rockchip,rk3399-gmac";
		reg = <0x00 0xfe300000 0x00 0x10000>;
		rockchip,grf = <0x15>;
		interrupts = <0x00 0x0c 0x04 0x00>;
		interrupt-names = "macirq";
		clocks = <0x08 0x69 0x08 0x67 0x08 0x68 0x08 0x66 0x08 0x6a 0x08 0xd5 0x08 0x166>;
		clock-names = "stmmaceth\0mac_clk_rx\0mac_clk_tx\0clk_mac_ref\0clk_mac_refout\0aclk_mac\0pclk_mac";
		resets = <0x08 0x89>;
		reset-names = "stmmaceth";
		power-domains = <0x16 0x16>;
		status = "okay";
		phy-supply = <0x17>;
		phy-mode = "rgmii";
		clock_in_out = "input";
		snps,reset-gpio = <0x18 0x0f 0x01>;
		snps,reset-active-low;
		snps,reset-delays-us = <0x00 0x2710 0xc350>;
		assigned-clocks = <0x08 0xa6>;
		assigned-clock-parents = <0x19>;
		pinctrl-names = "default";
		pinctrl-0 = <0x1a>;
		tx_delay = <0x28>;
		rx_delay = <0x11>;
	};

	dwmmc@fe310000 {
		compatible = "rockchip,rk3399-dw-mshc\0rockchip,rk3288-dw-mshc";
		reg = <0x00 0xfe310000 0x00 0x4000>;
		interrupts = <0x00 0x40 0x04 0x00>;
		clock-freq-min-max = <0x30d40 0x2faf080>;
		clocks = <0x08 0x1ee 0x08 0x4d 0x08 0x9c 0x08 0x9d>;
		clock-names = "biu\0ciu\0ciu-drive\0ciu-sample";
		fifo-depth = <0x100>;
		power-domains = <0x16 0x1c>;
		status = "okay";
		clock-frequency = <0x2faf080>;
		supports-sdio;
		bus-width = <0x04>;
		disable-wp;
		cap-sd-highspeed;
		cap-sdio-irq;
		keep-power-in-suspend;
		mmc-pwrseq = <0x1b>;
		non-removable;
		num-slots = <0x01>;
		pinctrl-names = "default";
		pinctrl-0 = <0x1c 0x1d 0x1e>;
		sd-uhs-sdr104;
	};

	dwmmc@fe320000 {
		compatible = "rockchip,rk3399-dw-mshc\0rockchip,rk3288-dw-mshc";
		reg = <0x00 0xfe320000 0x00 0x4000>;
		interrupts = <0x00 0x41 0x04 0x00>;
		clock-freq-min-max = <0x186a0 0x8f0d180>;
		clocks = <0x08 0x1ce 0x08 0x4c 0x08 0x9a 0x08 0x9b>;
		clock-names = "biu\0ciu\0ciu-drive\0ciu-sample";
		fifo-depth = <0x100>;
		power-domains = <0x16 0x1b>;
		status = "okay";
		clock-frequency = <0x8f0d180>;
		supports-sd;
		bus-width = <0x04>;
		cap-mmc-highspeed;
		cap-sd-highspeed;
		disable-wp;
		num-slots = <0x01>;
		vmmc-supply = <0x1f>;
		vqmmc-supply = <0x20>;
		pinctrl-names = "default";
		pinctrl-0 = <0x21 0x22 0x23 0x24>;
	};

	sdhci@fe330000 {
		compatible = "rockchip,rk3399-sdhci-5.1\0arasan,sdhci-5.1";
		reg = <0x00 0xfe330000 0x00 0x10000>;
		interrupts = <0x00 0x0b 0x04 0x00>;
		arasan,soc-ctl-syscon = <0x15>;
		assigned-clocks = <0x08 0x4e>;
		assigned-clock-rates = <0xbebc200>;
		clocks = <0x08 0x4e 0x08 0xf0>;
		clock-names = "clk_xin\0clk_ahb";
		clock-output-names = "emmc_cardclock";
		#clock-cells = <0x00>;
		phys = <0x25>;
		phy-names = "phy_arasan";
		power-domains = <0x16 0x17>;
		status = "okay";
		bus-width = <0x08>;
		mmc-hs400-1_8v;
		supports-emmc;
		non-removable;
		keep-power-in-suspend;
		mmc-hs400-enhanced-strobe;
		assigned-clock-parents = <0x08 0x05>;
		phandle = <0x99>;
	};

	usb@fe380000 {
		compatible = "generic-ehci";
		reg = <0x00 0xfe380000 0x00 0x20000>;
		interrupts = <0x00 0x1a 0x04 0x00>;
		clocks = <0x08 0x1c8 0x08 0x1c9 0x08 0xa8>;
		clock-names = "hclk_host0\0hclk_host0_arb\0usbphy0_480m";
		phys = <0x26>;
		phy-names = "usb";
		power-domains = <0x16 0x0e>;
		status = "okay";
	};

	usb@fe3a0000 {
		compatible = "generic-ohci";
		reg = <0x00 0xfe3a0000 0x00 0x20000>;
		interrupts = <0x00 0x1c 0x04 0x00>;
		clocks = <0x08 0x1c8 0x08 0x1c9 0x08 0xa8>;
		clock-names = "hclk_host0\0hclk_host0_arb\0usbphy0_480m";
		phys = <0x26>;
		phy-names = "usb";
		power-domains = <0x16 0x0e>;
		status = "okay";
	};

	usb@fe3c0000 {
		compatible = "generic-ehci";
		reg = <0x00 0xfe3c0000 0x00 0x20000>;
		interrupts = <0x00 0x1e 0x04 0x00>;
		clocks = <0x08 0x1ca 0x08 0x1cb 0x08 0xa9>;
		clock-names = "hclk_host1\0hclk_host1_arb\0usbphy1_480m";
		phys = <0x27>;
		phy-names = "usb";
		power-domains = <0x16 0x0e>;
		status = "okay";
	};

	usb@fe3e0000 {
		compatible = "generic-ohci";
		reg = <0x00 0xfe3e0000 0x00 0x20000>;
		interrupts = <0x00 0x20 0x04 0x00>;
		clocks = <0x08 0x1ca 0x08 0x1cb 0x08 0xa9>;
		clock-names = "hclk_host1\0hclk_host1_arb\0usbphy1_480m";
		phys = <0x27>;
		phy-names = "usb";
		power-domains = <0x16 0x0e>;
		status = "okay";
	};

	usb@fe800000 {
		compatible = "rockchip,rk3399-dwc3";
		clocks = <0x08 0x81 0x08 0x83 0x08 0xf6 0x08 0xf9>;
		clock-names = "ref_clk\0suspend_clk\0bus_clk\0grf_clk";
		power-domains = <0x16 0x18>;
		resets = <0x08 0x125>;
		reset-names = "usb3-otg";
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;
		status = "okay";
		extcon = <0x28>;

		dwc3@fe800000 {
			compatible = "snps,dwc3";
			reg = <0x00 0xfe800000 0x00 0x100000>;
			interrupts = <0x00 0x69 0x04 0x00>;
			dr_mode = "otg";
			phys = <0x29 0x2a>;
			phy-names = "usb2-phy\0usb3-phy";
			phy_type = "utmi_wide";
			snps,dis_enblslpm_quirk;
			snps,dis-u2-freeclk-exists-quirk;
			snps,dis_u2_susphy_quirk;
			snps,dis-del-phy-power-chg-quirk;
			snps,tx-ipgap-linecheck-dis-quirk;
			snps,xhci-slow-suspend-quirk;
			snps,usb3-warm-reset-on-resume-quirk;
			status = "okay";
		};
	};

	usb@fe900000 {
		compatible = "rockchip,rk3399-dwc3";
		clocks = <0x08 0x82 0x08 0x84 0x08 0xf7 0x08 0xf9>;
		clock-names = "ref_clk\0suspend_clk\0bus_clk\0grf_clk";
		power-domains = <0x16 0x18>;
		resets = <0x08 0x126>;
		reset-names = "usb3-otg";
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;
		status = "okay";

		dwc3@fe900000 {
			compatible = "snps,dwc3";
			reg = <0x00 0xfe900000 0x00 0x100000>;
			interrupts = <0x00 0x6e 0x04 0x00>;
			dr_mode = "host";
			phys = <0x2b 0x2c>;
			phy-names = "usb2-phy\0usb3-phy";
			phy_type = "utmi_wide";
			snps,dis_enblslpm_quirk;
			snps,dis-u2-freeclk-exists-quirk;
			snps,dis_u2_susphy_quirk;
			snps,dis-del-phy-power-chg-quirk;
			snps,tx-ipgap-linecheck-dis-quirk;
			snps,xhci-slow-suspend-quirk;
			snps,usb3-warm-reset-on-resume-quirk;
			status = "okay";
			phy-supply = <0x2d>;
		};
	};

	dp@fec00000 {
		compatible = "rockchip,rk3399-cdn-dp";
		reg = <0x00 0xfec00000 0x00 0x100000>;
		interrupts = <0x00 0x09 0x04 0x00>;
		clocks = <0x08 0x72 0x08 0x175 0x08 0xa1 0x08 0x16f>;
		clock-names = "core-clk\0pclk\0spdif\0grf";
		assigned-clocks = <0x08 0x72>;
		assigned-clock-rates = <0x5f5e100>;
		power-domains = <0x16 0x15>;
		phys = <0x2e>;
		resets = <0x08 0x103 0x08 0x148 0x08 0x14a 0x08 0xfd>;
		reset-names = "spdif\0dptx\0apb\0core";
		rockchip,grf = <0x15>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		#sound-dai-cells = <0x01>;
		status = "okay";
		extcon = <0x28>;
		phandle = <0xe3>;

		ports {
			#address-cells = <0x01>;
			#size-cells = <0x00>;

			port {
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				endpoint@0 {
					reg = <0x00>;
					remote-endpoint = <0x2f>;
					phandle = <0xab>;
				};

				endpoint@1 {
					reg = <0x01>;
					remote-endpoint = <0x30>;
					phandle = <0xa4>;
				};
			};
		};
	};

	interrupt-controller@fee00000 {
		compatible = "arm,gic-v3";
		#interrupt-cells = <0x04>;
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;
		interrupt-controller;
		reg = <0x00 0xfee00000 0x00 0x10000 0x00 0xfef00000 0x00 0xc0000 0x00 0xfff00000 0x00 0x10000 0x00 0xfff10000 0x00 0x10000 0x00 0xfff20000 0x00 0x10000>;
		interrupts = <0x01 0x09 0x04 0x00>;
		phandle = <0x01>;

		interrupt-controller@fee20000 {
			compatible = "arm,gic-v3-its";
			msi-controller;
			reg = <0x00 0xfee20000 0x00 0x20000>;
			phandle = <0x89>;
		};

		ppi-partitions {

			interrupt-partition-0 {
				affinity = <0x02 0x03 0x04 0x05>;
				phandle = <0x13>;
			};

			interrupt-partition-1 {
				affinity = <0x06 0x07>;
				phandle = <0x14>;
			};
		};
	};

	saradc@ff100000 {
		compatible = "rockchip,rk3399-saradc";
		reg = <0x00 0xff100000 0x00 0x100>;
		interrupts = <0x00 0x3e 0x04 0x00>;
		#io-channel-cells = <0x01>;
		clocks = <0x08 0x50 0x08 0x165>;
		clock-names = "saradc\0apb_pclk";
		resets = <0x08 0xd4>;
		reset-names = "saradc-apb";
		status = "okay";
		phandle = <0xd5>;
	};

	i2c@ff3c0000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff3c0000 0x00 0x1000>;
		clocks = <0x31 0x09 0x31 0x1b>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x39 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x32>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0xa8>;
		i2c-scl-falling-time-ns = <0x04>;
		clock-frequency = <0x61a80>;

		syr827@40 {
			compatible = "silergy,syr827";
			reg = <0x40>;
			vin-supply = <0x33>;
			regulator-compatible = "fan53555-reg";
			pinctrl-names = "default";
			pinctrl-0 = <0x34>;
			vsel-gpios = <0x35 0x11 0x00>;
			regulator-name = "vdd_cpu_b";
			regulator-min-microvolt = <0xadf34>;
			regulator-max-microvolt = <0x16e360>;
			regulator-ramp-delay = <0x3e8>;
			fcs,suspend-voltage-selector = <0x01>;
			regulator-always-on;
			regulator-boot-on;
			regulator-initial-state = <0x03>;
			phandle = <0x12>;

			regulator-state-mem {
				regulator-off-in-suspend;
			};
		};

		syr828@41 {
			compatible = "silergy,syr828";
			reg = <0x41>;
			vin-supply = <0x33>;
			regulator-compatible = "fan53555-reg";
			pinctrl-names = "default";
			pinctrl-0 = <0x36>;
			vsel-gpios = <0x35 0x0e 0x00>;
			regulator-name = "vdd_gpu";
			regulator-min-microvolt = <0xadf34>;
			regulator-max-microvolt = <0x16e360>;
			regulator-ramp-delay = <0x3e8>;
			fcs,suspend-voltage-selector = <0x01>;
			regulator-always-on;
			regulator-boot-on;
			regulator-initial-state = <0x03>;
			phandle = <0x9f>;

			regulator-state-mem {
				regulator-off-in-suspend;
			};
		};

		pmic@1b {
			compatible = "rockchip,rk808";
			reg = <0x1b>;
			interrupt-parent = <0x35>;
			interrupts = <0x15 0x08>;
			pinctrl-names = "default";
			pinctrl-0 = <0x37>;
			rockchip,system-power-controller;
			wakeup-source;
			#clock-cells = <0x01>;
			clock-output-names = "xin32k\0rk808-clkout2";
			vcc1-supply = <0x38>;
			vcc2-supply = <0x38>;
			vcc3-supply = <0x38>;
			vcc4-supply = <0x38>;
			vcc6-supply = <0x38>;
			vcc7-supply = <0x38>;
			vcc8-supply = <0x38>;
			vcc9-supply = <0x38>;
			vcc10-supply = <0x38>;
			vcc11-supply = <0x38>;
			vcc12-supply = <0x38>;
			vddio-supply = <0x39>;
			phandle = <0xcd>;

			regulators {

				DCDC_REG1 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0xb71b0>;
					regulator-max-microvolt = <0x149970>;
					regulator-ramp-delay = <0x1771>;
					regulator-name = "vdd_center";
					phandle = <0x94>;

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				DCDC_REG2 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0xb71b0>;
					regulator-max-microvolt = <0x149970>;
					regulator-ramp-delay = <0x1771>;
					regulator-name = "vdd_cpu_l";
					phandle = <0x0e>;

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				DCDC_REG3 {
					regulator-always-on;
					regulator-boot-on;
					regulator-name = "vcc_ddr";

					regulator-state-mem {
						regulator-on-in-suspend;
					};
				};

				DCDC_REG4 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x1b7740>;
					regulator-max-microvolt = <0x1b7740>;
					regulator-name = "vcc_1v8";

					regulator-state-mem {
						regulator-on-in-suspend;
						regulator-suspend-microvolt = <0x1b7740>;
					};
				};

				LDO_REG1 {
					regulator-min-microvolt = <0x1b7740>;
					regulator-max-microvolt = <0x1b7740>;
					regulator-name = "vcc1v8_dvp";
					phandle = <0x3f>;

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				LDO_REG2 {
					regulator-min-microvolt = <0x2ab980>;
					regulator-max-microvolt = <0x2ab980>;
					regulator-name = "vcc_avdd_2v8";
					phandle = <0x42>;

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				LDO_REG3 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x1b7740>;
					regulator-max-microvolt = <0x1b7740>;
					regulator-name = "vcc1v8_pmupll";

					regulator-state-mem {
						regulator-on-in-suspend;
						regulator-suspend-microvolt = <0x1b7740>;
					};
				};

				LDO_REG4 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x1b7740>;
					regulator-max-microvolt = <0x2dc6c0>;
					regulator-name = "vcc_sdio";
					phandle = <0x20>;

					regulator-state-mem {
						regulator-on-in-suspend;
						regulator-suspend-microvolt = <0x2dc6c0>;
					};
				};

				LDO_REG5 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x2dc6c0>;
					regulator-max-microvolt = <0x2dc6c0>;
					regulator-name = "vcca3v0_codec";

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				LDO_REG6 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x16e360>;
					regulator-max-microvolt = <0x16e360>;
					regulator-name = "vcc_1v5";

					regulator-state-mem {
						regulator-on-in-suspend;
						regulator-suspend-microvolt = <0x16e360>;
					};
				};

				LDO_REG7 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x1b7740>;
					regulator-max-microvolt = <0x1b7740>;
					regulator-name = "vcca1v8_codec";
					phandle = <0x98>;

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				LDO_REG8 {
					regulator-always-on;
					regulator-boot-on;
					regulator-min-microvolt = <0x2dc6c0>;
					regulator-max-microvolt = <0x2dc6c0>;
					regulator-name = "vcc_3v0";
					phandle = <0x39>;

					regulator-state-mem {
						regulator-on-in-suspend;
						regulator-suspend-microvolt = <0x2dc6c0>;
					};
				};

				SWITCH_REG1 {
					regulator-always-on;
					regulator-boot-on;
					regulator-name = "vcc3v3_s3";

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};

				SWITCH_REG2 {
					regulator-always-on;
					regulator-boot-on;
					regulator-name = "vcc3v3_s0";

					regulator-state-mem {
						regulator-off-in-suspend;
					};
				};
			};
		};
	};

	i2c@ff110000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff110000 0x00 0x1000>;
		clocks = <0x08 0x41 0x08 0x155>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x3b 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x3a>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0x12c>;
		i2c-scl-falling-time-ns = <0x0f>;
		clock-frequency = <0x61a80>;

		rt5651@1a {
			#sound-dai-cells = <0x00>;
			compatible = "rockchip,rt5651";
			reg = <0x1a>;
			clocks = <0x08 0x59>;
			clock-names = "mclk";
			pinctrl-names = "default";
			pinctrl-0 = <0x3b>;
			spk-con-gpio = <0x3c 0x0b 0x00>;
			hp-det-gpio = <0x3d 0x1c 0x00>;
			phandle = <0xd7>;
		};

		es7243@13 {
			status = "okay";
			compatible = "everest,es7243";
			reg = <0x13>;
		};

		camera-module@10 {
			status = "okay";
			compatible = "omnivision,ov9750-v4l2-i2c-subdev";
			reg = <0x10>;
			device_type = "v4l2-i2c-subdev";
			clocks = <0x08 0x89>;
			clock-names = "clk_cif_out";
			pinctrl-names = "rockchip,camera_default";
			pinctrl-0 = <0x3e>;
			rockchip,pd-gpio = <0x35 0x00 0x01>;
			rockchip,rst-gpio = <0x35 0x03 0x01>;
			dvp-supply = <0x3f>;
			dvdd-supply = <0x40>;
			avdd-3v2-supply = <0x41>;
			avdd-2v8-supply = <0x42>;
			rockchip,camera-module-regulator-names = "dvp\0dvdd\0avdd-3v2";
			rockchip,camera-module-regulator-voltages = <0x1b7740 0x1b7740 0x30d400>;
			rockchip,camera-module-mclk-name = "clk_cif_out";
			rockchip,camera-module-facing = "back";
			rockchip,camera-module-name = "MDG001";
			rockchip,camera-module-len-name = "NONE";
			rockchip,camera-module-fov-h = "80";
			rockchip,camera-module-fov-v = "65";
			rockchip,camera-module-orientation = <0x00>;
			rockchip,camera-module-iq-flip = <0x00>;
			rockchip,camera-module-iq-mirror = <0x00>;
			rockchip,camera-module-flip = <0x01>;
			rockchip,camera-module-mirror = <0x01>;
			rockchip,camera-module-defrect0 = <0x500 0x3c0 0x00 0x00 0x500 0x3c0>;
			rockchip,camera-module-flash-support = <0x00>;
			rockchip,camera-module-mipi-dphy-index = <0x00>;
			phandle = <0xe4>;
		};

		camera-module@36 {
			status = "okay";
			compatible = "omnivision,ov9750-v4l2-i2c-subdev";
			reg = <0x36>;
			device_type = "v4l2-i2c-subdev";
			clocks = <0x08 0x89>;
			clock-names = "clk_cif_out";
			pinctrl-names = "rockchip,camera_default";
			pinctrl-0 = <0x3e>;
			rockchip,pd-gpio = <0x35 0x01 0x01>;
			rockchip,rst-gpio = <0x35 0x04 0x01>;
			dvp-supply = <0x3f>;
			dvdd-supply = <0x40>;
			avdd-3v2-supply = <0x41>;
			avdd-2v8-supply = <0x42>;
			rockchip,camera-module-regulator-names = "dvp\0dvdd\0avdd-3v2";
			rockchip,camera-module-regulator-voltages = <0x1b7740 0x1b7740 0x30d400>;
			rockchip,camera-module-mclk-name = "clk_cif_out";
			rockchip,camera-module-facing = "back";
			rockchip,camera-module-name = "MDG001";
			rockchip,camera-module-len-name = "NONE";
			rockchip,camera-module-fov-h = "80";
			rockchip,camera-module-fov-v = "65";
			rockchip,camera-module-orientation = <0x00>;
			rockchip,camera-module-iq-flip = <0x00>;
			rockchip,camera-module-iq-mirror = <0x00>;
			rockchip,camera-module-flip = <0x01>;
			rockchip,camera-module-mirror = <0x01>;
			rockchip,camera-module-defrect0 = <0x500 0x3c0 0x00 0x00 0x500 0x3c0>;
			rockchip,camera-module-flash-support = <0x00>;
			rockchip,camera-module-mipi-dphy-index = <0x01>;
			phandle = <0xe5>;
		};
	};

	i2c@ff120000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff120000 0x00 0x1000>;
		clocks = <0x08 0x42 0x08 0x156>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x23 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x43>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0x12c>;
		i2c-scl-falling-time-ns = <0x0f>;
		clock-frequency = <0x61a80>;

		ina219@41 {
			compatible = "ina219";
			reg = <0x41>;
		};
	};

	i2c@ff130000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff130000 0x00 0x1000>;
		clocks = <0x08 0x43 0x08 0x157>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x22 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x44>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	i2c@ff140000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff140000 0x00 0x1000>;
		clocks = <0x08 0x44 0x08 0x158>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x26 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x45>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	i2c@ff150000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff150000 0x00 0x1000>;
		clocks = <0x08 0x45 0x08 0x159>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x25 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x46>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0x12c>;
		i2c-scl-falling-time-ns = <0x0f>;
		clock-frequency = <0x61a80>;

		ina219@47 {
			compatible = "ina219";
			reg = <0x47>;
		};
	};

	i2c@ff160000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff160000 0x00 0x1000>;
		clocks = <0x08 0x46 0x08 0x15a>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x24 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x47>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0x12c>;
		i2c-scl-falling-time-ns = <0x0f>;
		clock-frequency = <0x61a80>;

		ina219@40 {
			compatible = "ina219";
			reg = <0x40>;
		};
	};

	serial@ff180000 {
		compatible = "rockchip,rk3399-uart\0snps,dw-apb-uart";
		reg = <0x00 0xff180000 0x00 0x100>;
		clocks = <0x08 0x51 0x08 0x160>;
		clock-names = "baudclk\0apb_pclk";
		interrupts = <0x00 0x63 0x04 0x00>;
		reg-shift = <0x02>;
		reg-io-width = <0x04>;
		pinctrl-names = "default";
		pinctrl-0 = <0x48 0x49>;
		status = "okay";
		assigned-clocks = <0x08 0xac>;
		assigned-clock-parents = <0x08 0x05>;
	};

	serial@ff190000 {
		compatible = "rockchip,rk3399-uart\0snps,dw-apb-uart";
		reg = <0x00 0xff190000 0x00 0x100>;
		clocks = <0x08 0x52 0x08 0x161>;
		clock-names = "baudclk\0apb_pclk";
		interrupts = <0x00 0x62 0x04 0x00>;
		reg-shift = <0x02>;
		reg-io-width = <0x04>;
		pinctrl-names = "default";
		pinctrl-0 = <0x4a>;
		status = "disabled";
		assigned-clocks = <0x08 0xad>;
		assigned-clock-parents = <0x08 0x05>;
	};

	serial@ff1a0000 {
		compatible = "rockchip,rk3399-uart\0snps,dw-apb-uart";
		reg = <0x00 0xff1a0000 0x00 0x100>;
		clocks = <0x08 0x53 0x08 0x162>;
		clock-names = "baudclk\0apb_pclk";
		interrupts = <0x00 0x64 0x04 0x00>;
		reg-shift = <0x02>;
		reg-io-width = <0x04>;
		pinctrl-names = "default";
		pinctrl-0 = <0x4b>;
		status = "disabled";
		assigned-clocks = <0x08 0xad>;
		assigned-clock-parents = <0x08 0x05>;
	};

	serial@ff1b0000 {
		compatible = "rockchip,rk3399-uart\0snps,dw-apb-uart";
		reg = <0x00 0xff1b0000 0x00 0x100>;
		clocks = <0x08 0x54 0x08 0x163>;
		clock-names = "baudclk\0apb_pclk";
		interrupts = <0x00 0x65 0x04 0x00>;
		reg-shift = <0x02>;
		reg-io-width = <0x04>;
		pinctrl-names = "default";
		pinctrl-0 = <0x4c 0x4d 0x4e>;
		status = "disabled";
		assigned-clocks = <0x08 0xad>;
		assigned-clock-parents = <0x08 0x05>;
	};

	spi@ff1c0000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff1c0000 0x00 0x1000>;
		clocks = <0x08 0x47 0x08 0x15b>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x44 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x4f 0x50 0x51 0x52>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	spi@ff1d0000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff1d0000 0x00 0x1000>;
		clocks = <0x08 0x48 0x08 0x15c>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x35 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x53 0x54 0x55 0x56>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";

		flash@0 {
			compatible = "gigadevice,w25q64\0jedec,spi-nor";
			#address-cells = <0x01>;
			#size-cells = <0x01>;
			reg = <0x00>;
			m25p,fast-read;
			spi-max-frequency = <0x2faf080>;
		};
	};

	spi@ff1e0000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff1e0000 0x00 0x1000>;
		clocks = <0x08 0x49 0x08 0x15d>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x34 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x57 0x58 0x59 0x5a>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	spi@ff1f0000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff1f0000 0x00 0x1000>;
		clocks = <0x08 0x4a 0x08 0x15e>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x43 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x5b 0x5c 0x5d 0x5e>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	spi@ff200000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff200000 0x00 0x1000>;
		clocks = <0x08 0x4b 0x08 0x15f>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x84 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x5f 0x60 0x61 0x62>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	thermal-zones {

		soc-thermal {
			polling-delay-passive = <0x14>;
			polling-delay = <0x3e8>;
			sustainable-power = <0x3e8>;
			thermal-sensors = <0x63 0x00>;

			trips {

				trip-point-0 {
					temperature = <0x11170>;
					hysteresis = <0x7d0>;
					type = "passive";
				};

				trip-point-1 {
					temperature = <0x14c08>;
					hysteresis = <0x7d0>;
					type = "passive";
					phandle = <0x64>;
				};

				soc-crit {
					temperature = <0x17318>;
					hysteresis = <0x7d0>;
					type = "critical";
				};
			};

			cooling-maps {

				map0 {
					trip = <0x64>;
					cooling-device = <0x02 0xffffffff 0xffffffff>;
					contribution = <0x1000>;
				};

				map1 {
					trip = <0x64>;
					cooling-device = <0x06 0xffffffff 0xffffffff>;
					contribution = <0x400>;
				};

				map2 {
					trip = <0x64>;
					cooling-device = <0x65 0xffffffff 0xffffffff>;
					contribution = <0x1000>;
				};
			};
		};

		gpu-thermal {
			polling-delay-passive = <0x64>;
			polling-delay = <0x3e8>;
			thermal-sensors = <0x63 0x01>;
		};
	};

	tsadc@ff260000 {
		compatible = "rockchip,rk3399-tsadc";
		reg = <0x00 0xff260000 0x00 0x100>;
		interrupts = <0x00 0x61 0x04 0x00>;
		rockchip,grf = <0x15>;
		clocks = <0x08 0x4f 0x08 0x164>;
		clock-names = "tsadc\0apb_pclk";
		assigned-clocks = <0x08 0x4f>;
		assigned-clock-rates = <0xb71b0>;
		resets = <0x08 0xe8>;
		reset-names = "tsadc-apb";
		pinctrl-names = "init\0default\0sleep";
		pinctrl-0 = <0x66>;
		pinctrl-1 = <0x67>;
		pinctrl-2 = <0x66>;
		#thermal-sensor-cells = <0x01>;
		rockchip,hw-tshut-temp = <0x17318>;
		status = "okay";
		rockchip,hw-tshut-mode = <0x01>;
		rockchip,hw-tshut-polarity = <0x01>;
		phandle = <0x63>;
	};

	qos@ffa58000 {
		compatible = "syscon";
		reg = <0x00 0xffa58000 0x00 0x20>;
		phandle = <0x6f>;
	};

	qos@ffa5c000 {
		compatible = "syscon";
		reg = <0x00 0xffa5c000 0x00 0x20>;
		phandle = <0x70>;
	};

	qos@ffa60080 {
		compatible = "syscon";
		reg = <0x00 0xffa60080 0x00 0x20>;
		phandle = <0x72>;
	};

	qos@ffa60100 {
		compatible = "syscon";
		reg = <0x00 0xffa60100 0x00 0x20>;
		phandle = <0x73>;
	};

	qos@ffa60180 {
		compatible = "syscon";
		reg = <0x00 0xffa60180 0x00 0x20>;
		phandle = <0x74>;
	};

	qos@ffa70000 {
		compatible = "syscon";
		reg = <0x00 0xffa70000 0x00 0x20>;
		phandle = <0x77>;
	};

	qos@ffa70080 {
		compatible = "syscon";
		reg = <0x00 0xffa70080 0x00 0x20>;
		phandle = <0x78>;
	};

	qos@ffa74000 {
		compatible = "syscon";
		reg = <0x00 0xffa74000 0x00 0x20>;
		phandle = <0x75>;
	};

	qos@ffa76000 {
		compatible = "syscon";
		reg = <0x00 0xffa76000 0x00 0x20>;
		phandle = <0x76>;
	};

	qos@ffa90000 {
		compatible = "syscon";
		reg = <0x00 0xffa90000 0x00 0x20>;
		phandle = <0x79>;
	};

	qos@ffa98000 {
		compatible = "syscon";
		reg = <0x00 0xffa98000 0x00 0x20>;
		phandle = <0x68>;
	};

	qos@ffaa0000 {
		compatible = "syscon";
		reg = <0x00 0xffaa0000 0x00 0x20>;
		phandle = <0x7a>;
	};

	qos@ffaa0080 {
		compatible = "syscon";
		reg = <0x00 0xffaa0080 0x00 0x20>;
		phandle = <0x7b>;
	};

	qos@ffaa8000 {
		compatible = "syscon";
		reg = <0x00 0xffaa8000 0x00 0x20>;
		phandle = <0x7c>;
	};

	qos@ffaa8080 {
		compatible = "syscon";
		reg = <0x00 0xffaa8080 0x00 0x20>;
		phandle = <0x7d>;
	};

	qos@ffab0000 {
		compatible = "syscon";
		reg = <0x00 0xffab0000 0x00 0x20>;
		phandle = <0x69>;
	};

	qos@ffab0080 {
		compatible = "syscon";
		reg = <0x00 0xffab0080 0x00 0x20>;
		phandle = <0x6a>;
	};

	qos@ffab8000 {
		compatible = "syscon";
		reg = <0x00 0xffab8000 0x00 0x20>;
		phandle = <0x6b>;
	};

	qos@ffac0000 {
		compatible = "syscon";
		reg = <0x00 0xffac0000 0x00 0x20>;
		phandle = <0x6c>;
	};

	qos@ffac0080 {
		compatible = "syscon";
		reg = <0x00 0xffac0080 0x00 0x20>;
		phandle = <0x6d>;
	};

	qos@ffac8000 {
		compatible = "syscon";
		reg = <0x00 0xffac8000 0x00 0x20>;
		phandle = <0x7e>;
	};

	qos@ffac8080 {
		compatible = "syscon";
		reg = <0x00 0xffac8080 0x00 0x20>;
		phandle = <0x7f>;
	};

	qos@ffad0000 {
		compatible = "syscon";
		reg = <0x00 0xffad0000 0x00 0x20>;
		phandle = <0x80>;
	};

	qos@ffad8080 {
		compatible = "syscon";
		reg = <0x00 0xffad8080 0x00 0x20>;
		phandle = <0x71>;
	};

	qos@ffae0000 {
		compatible = "syscon";
		reg = <0x00 0xffae0000 0x00 0x20>;
		phandle = <0x6e>;
	};

	power-management@ff310000 {
		compatible = "rockchip,rk3399-pmu\0syscon\0simple-mfd";
		reg = <0x00 0xff310000 0x00 0x1000>;

		power-controller {
			compatible = "rockchip,rk3399-power-controller";
			#power-domain-cells = <0x01>;
			#address-cells = <0x01>;
			#size-cells = <0x00>;
			phandle = <0x16>;

			pd_iep@34 {
				reg = <0x22>;
				clocks = <0x08 0xe1 0x08 0x1dd>;
				pm_qos = <0x68>;
			};

			pd_rga@33 {
				reg = <0x21>;
				clocks = <0x08 0xdc 0x08 0x1e5>;
				pm_qos = <0x69 0x6a>;
			};

			pd_vcodec@31 {
				reg = <0x1f>;
				clocks = <0x08 0xeb 0x08 0x1ea>;
				pm_qos = <0x6b>;
			};

			pd_vdu@32 {
				reg = <0x20>;
				clocks = <0x08 0xed 0x08 0x1ec>;
				pm_qos = <0x6c 0x6d>;
			};

			pd_gpu@35 {
				reg = <0x23>;
				clocks = <0x08 0xd0>;
				pm_qos = <0x6e>;
			};

			pd_edp@25 {
				reg = <0x19>;
				clocks = <0x08 0x16c>;
			};

			pd_emmc@23 {
				reg = <0x17>;
				clocks = <0x08 0xf0>;
				pm_qos = <0x6f>;
			};

			pd_gmac@22 {
				reg = <0x16>;
				clocks = <0x08 0xd5 0x08 0x166>;
				pm_qos = <0x70>;
			};

			pd_perihp@14 {
				reg = <0x0e>;
				#address-cells = <0x01>;
				#size-cells = <0x00>;
				clocks = <0x08 0xc0>;
				pm_qos = <0x71 0x72 0x73 0x74>;

				pd_sd@27 {
					reg = <0x1b>;
					clocks = <0x08 0x1ce 0x08 0x4c>;
					pm_qos = <0x75>;
				};
			};

			pd_sdioaudio@28 {
				reg = <0x1c>;
				clocks = <0x08 0x1ee>;
				pm_qos = <0x76>;
			};

			pd_usb3@24 {
				reg = <0x18>;
				clocks = <0x08 0xf4>;
				pm_qos = <0x77 0x78>;
			};

			pd_vio@15 {
				reg = <0x0f>;
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				pd_hdcp@21 {
					reg = <0x15>;
					clocks = <0x08 0xde 0x08 0x1e7 0x08 0x172>;
					pm_qos = <0x79>;
				};

				pd_isp0@19 {
					reg = <0x13>;
					clocks = <0x08 0xe5 0x08 0x1df>;
					pm_qos = <0x7a 0x7b>;
				};

				pd_isp1@20 {
					reg = <0x14>;
					clocks = <0x08 0xe6 0x08 0x1e0>;
					pm_qos = <0x7c 0x7d>;
				};

				pd_tcpc0@RK3399_PD_TCPC0 {
					reg = <0x08>;
					clocks = <0x08 0x7e 0x08 0x7d>;
				};

				pd_tcpc1@RK3399_PD_TCPC1 {
					reg = <0x09>;
					clocks = <0x08 0x80 0x08 0x7f>;
				};

				pd_vo@16 {
					reg = <0x10>;
					#address-cells = <0x01>;
					#size-cells = <0x00>;

					pd_vopb@17 {
						reg = <0x11>;
						clocks = <0x08 0xd9 0x08 0x1d9>;
						pm_qos = <0x7e 0x7f>;
					};

					pd_vopl@18 {
						reg = <0x12>;
						clocks = <0x08 0xdb 0x08 0x1db>;
						pm_qos = <0x80>;
					};
				};
			};
		};
	};

	syscon@ff320000 {
		compatible = "rockchip,rk3399-pmugrf\0syscon\0simple-mfd";
		reg = <0x00 0xff320000 0x00 0x1000>;
		#address-cells = <0x01>;
		#size-cells = <0x01>;
		phandle = <0x90>;

		io-domains {
			compatible = "rockchip,rk3399-pmu-io-voltage-domain";
			status = "okay";
			pmu1830-supply = <0x39>;
		};

		reboot-mode {
			compatible = "syscon-reboot-mode";
			offset = <0x300>;
			mode-bootloader = <0x5242c301>;
			mode-charge = <0x5242c30b>;
			mode-fastboot = <0x5242c309>;
			mode-loader = <0x5242c301>;
			mode-normal = <0x5242c300>;
			mode-recovery = <0x5242c303>;
			mode-ums = <0x5242c30c>;
		};

		pmu-pvtm {
			compatible = "rockchip,rk3399-pmu-pvtm";
			clocks = <0x31 0x07>;
			clock-names = "pmu";
			resets = <0x08 0x1b>;
			reset-names = "pmu";
			status = "disabled";
		};
	};

	spi@ff350000 {
		compatible = "rockchip,rk3399-spi\0rockchip,rk3066-spi";
		reg = <0x00 0xff350000 0x00 0x1000>;
		clocks = <0x31 0x03 0x31 0x1f>;
		clock-names = "spiclk\0apb_pclk";
		interrupts = <0x00 0x3c 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x81 0x82 0x83 0x84>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	serial@ff370000 {
		compatible = "rockchip,rk3399-uart\0snps,dw-apb-uart";
		reg = <0x00 0xff370000 0x00 0x100>;
		clocks = <0x31 0x06 0x31 0x22>;
		clock-names = "baudclk\0apb_pclk";
		interrupts = <0x00 0x66 0x04 0x00>;
		reg-shift = <0x02>;
		reg-io-width = <0x04>;
		pinctrl-names = "default";
		pinctrl-0 = <0x85>;
		status = "disabled";
		assigned-clocks = <0x31 0x0c>;
		assigned-clock-parents = <0x31 0x01>;
	};

	i2c@ff3d0000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff3d0000 0x00 0x1000>;
		clocks = <0x31 0x0a 0x31 0x1c>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x38 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x86>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";
		i2c-scl-rising-time-ns = <0x1db>;
		i2c-scl-falling-time-ns = <0x1a>;

		fusb30x@22 {
			compatible = "fairchild,fusb302";
			reg = <0x22>;
			pinctrl-names = "default";
			pinctrl-0 = <0x87>;
			int-n-gpios = <0x35 0x02 0x00>;
			vbus-5v-gpios = <0x3d 0x15 0x00>;
			status = "okay";
			phandle = <0x28>;
		};

		gt1x@14 {
			status = "okay";
			compatible = "goodix,gt1x";
			reg = <0x14>;
			goodix,rst-gpio = <0x3d 0x16 0x00>;
			goodix,irq-gpio = <0x35 0x14 0x08>;
			goodix,enable-gpio = <0x35 0x0d 0x00>;
		};
	};

	i2c@ff3e0000 {
		compatible = "rockchip,rk3399-i2c";
		reg = <0x00 0xff3e0000 0x00 0x1000>;
		clocks = <0x31 0x0b 0x31 0x1d>;
		clock-names = "i2c\0pclk";
		interrupts = <0x00 0x3a 0x04 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0x88>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";
	};

	pcie-phy {
		compatible = "rockchip,rk3399-pcie-phy";
		#phy-cells = <0x00>;
		rockchip,grf = <0x15>;
		clocks = <0x08 0x8a>;
		clock-names = "refclk";
		resets = <0x08 0x87>;
		reset-names = "phy";
		status = "disabled";
		phandle = <0x8b>;
	};

	pcie@f8000000 {
		compatible = "rockchip,rk3399-pcie";
		#address-cells = <0x03>;
		#size-cells = <0x02>;
		aspm-no-l0s;
		clocks = <0x08 0xc5 0x08 0xc4 0x08 0x147 0x08 0xa0>;
		clock-names = "aclk\0aclk-perf\0hclk\0pm";
		bus-range = <0x00 0x1f>;
		max-link-speed = <0x01>;
		linux,pci-domain = <0x00>;
		msi-map = <0x00 0x89 0x00 0x1000>;
		interrupts = <0x00 0x31 0x04 0x00 0x00 0x32 0x04 0x00 0x00 0x33 0x04 0x00>;
		interrupt-names = "sys\0legacy\0client";
		#interrupt-cells = <0x01>;
		interrupt-map-mask = <0x00 0x00 0x00 0x07>;
		interrupt-map = <0x00 0x00 0x00 0x01 0x8a 0x00 0x00 0x00 0x00 0x02 0x8a 0x01 0x00 0x00 0x00 0x03 0x8a 0x02 0x00 0x00 0x00 0x04 0x8a 0x03>;
		phys = <0x8b>;
		phy-names = "pcie-phy";
		ranges = <0x83000000 0x00 0xfa000000 0x00 0xfa000000 0x00 0x1e00000 0x81000000 0x00 0xfbe00000 0x00 0xfbe00000 0x00 0x100000>;
		reg = <0x00 0xf8000000 0x00 0x2000000 0x00 0xfd000000 0x00 0x1000000>;
		reg-names = "axi-base\0apb-base";
		resets = <0x08 0x82 0x08 0x83 0x08 0x84 0x08 0x85 0x08 0x86 0x08 0x81 0x08 0x80>;
		reset-names = "core\0mgmt\0mgmt-sticky\0pipe\0pm\0pclk\0aclk";
		status = "disabled";

		interrupt-controller {
			interrupt-controller;
			#address-cells = <0x00>;
			#interrupt-cells = <0x01>;
			phandle = <0x8a>;
		};
	};

	pwm@ff420000 {
		compatible = "rockchip,rk3399-pwm\0rockchip,rk3288-pwm";
		reg = <0x00 0xff420000 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0x8c>;
		clocks = <0x31 0x1e>;
		clock-names = "pwm";
		status = "okay";
		phandle = <0xd2>;
	};

	pwm@ff420010 {
		compatible = "rockchip,rk3399-pwm\0rockchip,rk3288-pwm";
		reg = <0x00 0xff420010 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0x8d>;
		clocks = <0x31 0x1e>;
		clock-names = "pwm";
		status = "disabled";
	};

	pwm@ff420020 {
		compatible = "rockchip,rk3399-pwm\0rockchip,rk3288-pwm";
		reg = <0x00 0xff420020 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0x8e>;
		clocks = <0x31 0x1e>;
		clock-names = "pwm";
		status = "disabled";
	};

	pwm@ff420030 {
		compatible = "rockchip,rk3399-pwm\0rockchip,rk3288-pwm";
		reg = <0x00 0xff420030 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0x8f>;
		clocks = <0x31 0x1e>;
		clock-names = "pwm";
		status = "disabled";
	};

	dfi@ff630000 {
		reg = <0x00 0xff630000 0x00 0x4000>;
		compatible = "rockchip,rk3399-dfi";
		rockchip,pmu = <0x90>;
		clocks = <0x08 0x179>;
		clock-names = "pclk_ddr_mon";
		status = "disabled";
		phandle = <0x91>;
	};

	dmc {
		compatible = "rockchip,rk3399-dmc";
		devfreq-events = <0x91>;
		interrupts = <0x00 0x01 0x04 0x00>;
		clocks = <0x08 0xaa>;
		clock-names = "dmc_clk";
		ddr_timing = <0x92>;
		upthreshold = <0x28>;
		downdifferential = <0x14>;
		system-status-freq = <0x01 0xc3500 0x08 0x80e80 0x02 0x30d40 0x20 0x30d40 0x10 0x927c0 0x10000 0xc3500 0x2000 0xc3500 0x1000 0x61a80 0xc00 0x927c0 0x4000 0x927c0>;
		auto-min-freq = <0x30d40>;
		auto-freq-en = <0x01>;
		status = "disalbed";
		operating-points-v2 = <0x93>;
		center-supply = <0x94>;
		vop-bw-dmc-freq = <0x00 0x241 0x30d40 0x242 0x6a5 0x493e0 0x6a6 0x1869f 0x61a80>;
		phandle = <0xae>;
	};

	vpu_service@ff650000 {
		compatible = "rockchip,vpu_service";
		rockchip,grf = <0x15>;
		iommus = <0x95>;
		iommu_enabled = <0x01>;
		reg = <0x00 0xff650000 0x00 0x800>;
		interrupts = <0x00 0x71 0x04 0x00 0x00 0x72 0x04 0x00>;
		interrupt-names = "irq_dec\0irq_enc";
		clocks = <0x08 0xeb 0x08 0x1ea>;
		clock-names = "aclk_vcodec\0hclk_vcodec";
		resets = <0x08 0x53 0x08 0x51>;
		reset-names = "video_h\0video_a";
		power-domains = <0x16 0x1f>;
		dev_mode = <0x00>;
		allocator = <0x01>;
		status = "okay";
	};

	iommu@ff650800 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff650800 0x00 0x40>;
		interrupts = <0x00 0x73 0x04 0x00>;
		interrupt-names = "vpu_mmu";
		clocks = <0x08 0xeb 0x08 0x1ea>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x1f>;
		#iommu-cells = <0x00>;
		phandle = <0x95>;
	};

	rkvdec@ff660000 {
		compatible = "rockchip,rkvdec";
		rockchip,grf = <0x15>;
		iommus = <0x96>;
		iommu_enabled = <0x01>;
		reg = <0x00 0xff660000 0x00 0x400>;
		interrupts = <0x00 0x74 0x04 0x00>;
		interrupt-names = "irq_dec";
		clocks = <0x08 0xed 0x08 0x1ec 0x08 0x9f 0x08 0x9e>;
		clock-names = "aclk_vcodec\0hclk_vcodec\0clk_cabac\0clk_core";
		resets = <0x08 0x5b 0x08 0x59 0x08 0x5c 0x08 0x5d 0x08 0x58 0x08 0x5a>;
		reset-names = "video_h\0video_a\0video_core\0video_cabac\0niu_a\0niu_h";
		power-domains = <0x16 0x20>;
		dev_mode = <0x02>;
		allocator = <0x01>;
		status = "okay";
	};

	iommu@ff660480 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff660480 0x00 0x40 0x00 0xff6604c0 0x00 0x40>;
		interrupts = <0x00 0x75 0x04 0x00>;
		interrupt-names = "vdec_mmu";
		clocks = <0x08 0xed 0x08 0x1ec>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x20>;
		#iommu-cells = <0x00>;
		phandle = <0x96>;
	};

	iep@ff670000 {
		compatible = "rockchip,iep";
		iommu_enabled = <0x01>;
		iommus = <0x97>;
		reg = <0x00 0xff670000 0x00 0x800>;
		interrupts = <0x00 0x2a 0x04 0x00>;
		clocks = <0x08 0xe1 0x08 0x1dd>;
		clock-names = "aclk_iep\0hclk_iep";
		power-domains = <0x16 0x22>;
		allocator = <0x01>;
		version = <0x02>;
		status = "okay";
	};

	iommu@ff670800 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff670800 0x00 0x40>;
		interrupts = <0x00 0x2a 0x04 0x00>;
		interrupt-names = "iep_mmu";
		#iommu-cells = <0x00>;
		status = "okay";
		phandle = <0x97>;
	};

	rga@ff680000 {
		compatible = "rockchip,rga2";
		reg = <0x00 0xff680000 0x00 0x1000>;
		interrupts = <0x00 0x37 0x04 0x00>;
		clocks = <0x08 0xdc 0x08 0x1e5 0x08 0x6d>;
		clock-names = "aclk_rga\0hclk_rga\0clk_rga";
		resets = <0x08 0x6a 0x08 0x67 0x08 0x69>;
		reset-names = "core\0axi\0ahb";
		power-domains = <0x16 0x21>;
		status = "okay";
		dev_mode = <0x01>;
		dma-coherent;
	};

	efuse@ff690000 {
		compatible = "rockchip,rk3399-efuse";
		reg = <0x00 0xff690000 0x00 0x80>;
		#address-cells = <0x01>;
		#size-cells = <0x01>;
		clocks = <0x08 0x17d>;
		clock-names = "pclk_efuse";

		id@7 {
			reg = <0x07 0x10>;
			phandle = <0xda>;
		};

		cpub-leakage@17 {
			reg = <0x17 0x01>;
			phandle = <0xc8>;
		};

		gpu-leakage@18 {
			reg = <0x18 0x01>;
			phandle = <0xc9>;
		};

		center-leakage@19 {
			reg = <0x19 0x01>;
		};

		cpul-leakage@1a {
			reg = <0x1a 0x01>;
			phandle = <0xc7>;
		};

		logic-leakage@1b {
			reg = <0x1b 0x01>;
		};

		wafer-info@1c {
			reg = <0x1c 0x01>;
		};
	};

	pmu-clock-controller@ff750000 {
		compatible = "rockchip,rk3399-pmucru";
		reg = <0x00 0xff750000 0x00 0x1000>;
		#clock-cells = <0x01>;
		#reset-cells = <0x01>;
		assigned-clocks = <0x31 0x01 0x31 0x2c>;
		assigned-clock-rates = <0x284af100 0x5c81a40>;
		phandle = <0x31>;
	};

	clock-controller@ff760000 {
		compatible = "rockchip,rk3399-cru";
		reg = <0x00 0xff760000 0x00 0x1000>;
		#clock-cells = <0x01>;
		#reset-cells = <0x01>;
		assigned-clocks = <0x08 0xc0 0x08 0xc2 0x08 0x1c2 0x08 0x4c 0x08 0xf0 0x08 0xcd 0x08 0x1cd 0x08 0x9f 0x08 0x9e 0x08 0xf4 0x08 0xbe 0x08 0xc9 0x08 0x186 0x08 0xd5 0x08 0x88 0x08 0x87 0x08 0x08 0x08 0x09 0x08 0x06 0x08 0xd0 0x08 0x05 0x08 0xc0 0x08 0x1c0 0x08 0x140 0x08 0xc2 0x08 0x1c1 0x08 0x142 0x08 0x1c2 0x08 0x143 0x08 0x41 0x08 0x42 0x08 0x43 0x08 0x44 0x08 0x45 0x08 0x46 0x08 0x47 0x08 0x48 0x08 0x49 0x08 0x4a 0x08 0x4b 0x08 0xfa 0x08 0xe5 0x08 0xe6 0x08 0x6b 0x08 0x6c 0x08 0x16a 0x08 0xde 0x08 0xe3 0x08 0x1cd 0x08 0x85 0x08 0x86 0x08 0x4e 0x08 0xf0 0x08 0xcd 0x08 0xe1 0x08 0xdc 0x08 0x6d 0x08 0xed 0x08 0xeb 0x08 0x178 0x08 0xd5 0x08 0x9f 0x08 0x9e 0x08 0xf4 0x08 0xbe 0x08 0xc9 0x08 0x186 0x08 0x88 0x08 0x87 0x08 0xd9 0x08 0x1d9 0x08 0xdb 0x08 0x1db>;
		assigned-clock-rates = <0x47868c0 0x2faf080 0x2faf080 0x2faf080 0x2faf080 0x5f5e100 0x2faf080 0x8f0d180 0x8f0d180 0x8f0d180 0x2faf080 0x8f0d180 0x2faf080 0x5f5e100 0x47868c0 0x47868c0 0x30a32c00 0x30a32c00 0x23c34600 0xbebc200 0x2faf0800 0x8f0d180 0x47868c0 0x23c3460 0x5f5e100 0x5f5e100 0x2faf080 0x5f5e100 0x2faf080 0x5f5e100 0x5f5e100 0x5f5e100 0x5f5e100 0x5f5e100 0x5f5e100 0x2faf080 0x2faf080 0x2faf080 0x2faf080 0x2faf080 0xbebc200 0x17d78400 0x17d78400 0x5f5e100 0x5f5e100 0x5f5e100 0x17d78400 0x17d78400 0xbebc200 0x5f5e100 0xbebc200 0xbebc200 0x5f5e100 0x17d78400 0x17d78400 0x17d78400 0x17d78400 0x11e1a300 0x17d78400 0xbebc200 0x17d78400 0x11e1a300 0x11e1a300 0x11e1a300 0x11e1a300 0x11e1a300 0x5f5e100 0x8f0d180 0x8f0d180 0x17d78400 0x5f5e100 0x17d78400 0x5f5e100>;
		phandle = <0x08>;
	};

	syscon@ff770000 {
		compatible = "rockchip,rk3399-grf\0syscon\0simple-mfd";
		reg = <0x00 0xff770000 0x00 0x10000>;
		#address-cells = <0x01>;
		#size-cells = <0x01>;
		phandle = <0x15>;

		io-domains {
			compatible = "rockchip,rk3399-io-voltage-domain";
			status = "okay";
			bt656-supply = <0x39>;
			audio-supply = <0x98>;
			sdmmc-supply = <0x20>;
			gpio1830-supply = <0x39>;
		};

		phy@f780 {
			compatible = "rockchip,rk3399-emmc-phy";
			reg = <0xf780 0x24>;
			clocks = <0x99>;
			clock-names = "emmcclk";
			#phy-cells = <0x00>;
			status = "okay";
			phandle = <0x25>;
		};

		usb2-phy@e450 {
			compatible = "rockchip,rk3399-usb2phy";
			reg = <0xe450 0x10>;
			clocks = <0x08 0x7b>;
			clock-names = "phyclk";
			#clock-cells = <0x00>;
			clock-output-names = "clk_usbphy0_480m";
			status = "okay";
			extcon = <0x28>;

			otg-port {
				#phy-cells = <0x00>;
				interrupts = <0x00 0x67 0x04 0x00 0x00 0x68 0x04 0x00 0x00 0x6a 0x04 0x00>;
				interrupt-names = "otg-bvalid\0otg-id\0linestate";
				status = "okay";
				phandle = <0x29>;
			};

			host-port {
				#phy-cells = <0x00>;
				interrupts = <0x00 0x1b 0x04 0x00>;
				interrupt-names = "linestate";
				status = "okay";
				phy-supply = <0x2d>;
				phandle = <0x26>;
			};
		};

		usb2-phy@e460 {
			compatible = "rockchip,rk3399-usb2phy";
			reg = <0xe460 0x10>;
			clocks = <0x08 0x7c>;
			clock-names = "phyclk";
			#clock-cells = <0x00>;
			clock-output-names = "clk_usbphy1_480m";
			status = "okay";

			otg-port {
				#phy-cells = <0x00>;
				interrupts = <0x00 0x6c 0x04 0x00 0x00 0x6d 0x04 0x00 0x00 0x6f 0x04 0x00>;
				interrupt-names = "otg-bvalid\0otg-id\0linestate";
				status = "okay";
				phandle = <0x2b>;
			};

			host-port {
				#phy-cells = <0x00>;
				interrupts = <0x00 0x1f 0x04 0x00>;
				interrupt-names = "linestate";
				status = "okay";
				phy-supply = <0x2d>;
				phandle = <0x27>;
			};
		};

		mipi-dphy-rx0 {
			compatible = "rockchip,rk3399-mipi-dphy";
			clocks = <0x08 0x77 0x08 0xa5 0x08 0x16f>;
			clock-names = "dphy-ref\0dphy-cfg\0grf";
			power-domains = <0x16 0x0f>;
			status = "disabled";
		};

		pvtm {
			compatible = "rockchip,rk3399-pvtm";
			clocks = <0x08 0x73 0x08 0x74 0x08 0x75 0x08 0x76>;
			clock-names = "core_l\0core_b\0gpu\0ddr";
			resets = <0x08 0x1f 0x08 0x2f 0x08 0x123 0x08 0x4f>;
			reset-names = "core_l\0core_b\0gpu\0ddr";
			status = "okay";
		};
	};

	phy@ff7c0000 {
		compatible = "rockchip,rk3399-typec-phy";
		reg = <0x00 0xff7c0000 0x00 0x40000>;
		rockchip,grf = <0x15>;
		#phy-cells = <0x01>;
		clocks = <0x08 0x7e 0x08 0x7d>;
		clock-names = "tcpdcore\0tcpdphy-ref";
		assigned-clocks = <0x08 0x7e>;
		assigned-clock-rates = <0x2faf080>;
		power-domains = <0x16 0x08>;
		resets = <0x08 0x95 0x08 0x94 0x08 0x14c>;
		reset-names = "uphy\0uphy-pipe\0uphy-tcphy";
		rockchip,typec-conn-dir = <0xe580 0x00 0x10>;
		rockchip,usb3tousb2-en = <0xe580 0x03 0x13>;
		rockchip,usb3-host-disable = <0x2434 0x00 0x10>;
		rockchip,usb3-host-port = <0x2434 0x0c 0x1c>;
		rockchip,external-psm = <0xe588 0x0e 0x1e>;
		rockchip,pipe-status = <0xe5c0 0x00 0x00>;
		rockchip,uphy-dp-sel = <0x6268 0x13 0x13>;
		status = "okay";
		extcon = <0x28>;

		dp-port {
			#phy-cells = <0x00>;
			phandle = <0x2e>;
		};

		usb3-port {
			#phy-cells = <0x00>;
			phandle = <0x2a>;
		};
	};

	phy@ff800000 {
		compatible = "rockchip,rk3399-typec-phy";
		reg = <0x00 0xff800000 0x00 0x40000>;
		rockchip,grf = <0x15>;
		#phy-cells = <0x01>;
		clocks = <0x08 0x80 0x08 0x7f>;
		clock-names = "tcpdcore\0tcpdphy-ref";
		assigned-clocks = <0x08 0x80>;
		assigned-clock-rates = <0x2faf080>;
		power-domains = <0x16 0x09>;
		resets = <0x08 0x9d 0x08 0x9c 0x08 0x14d>;
		reset-names = "uphy\0uphy-pipe\0uphy-tcphy";
		rockchip,typec-conn-dir = <0xe58c 0x00 0x10>;
		rockchip,usb3tousb2-en = <0xe58c 0x03 0x13>;
		rockchip,usb3-host-disable = <0x2444 0x00 0x10>;
		rockchip,usb3-host-port = <0x2444 0x0c 0x1c>;
		rockchip,external-psm = <0xe594 0x0e 0x1e>;
		rockchip,pipe-status = <0xe5c0 0x10 0x10>;
		rockchip,uphy-dp-sel = <0x6268 0x03 0x13>;
		status = "okay";

		dp-port {
			#phy-cells = <0x00>;
		};

		usb3-port {
			#phy-cells = <0x00>;
			phandle = <0x2c>;
		};
	};

	watchdog@ff848000 {
		compatible = "snps,dw-wdt";
		reg = <0x00 0xff848000 0x00 0x100>;
		clocks = <0x08 0x17c>;
		interrupts = <0x00 0x78 0x04 0x00>;
	};

	rktimer@ff850000 {
		compatible = "rockchip,rk3399-timer";
		reg = <0x00 0xff850000 0x00 0x1000>;
		interrupts = <0x00 0x51 0x04 0x00>;
		clocks = <0x08 0x168 0x08 0x5a>;
		clock-names = "pclk\0timer";
	};

	spdif@ff870000 {
		compatible = "rockchip,rk3399-spdif";
		reg = <0x00 0xff870000 0x00 0x1000>;
		interrupts = <0x00 0x42 0x04 0x00>;
		dmas = <0x9a 0x07>;
		dma-names = "tx";
		clock-names = "mclk\0hclk";
		clocks = <0x08 0x55 0x08 0x1d7>;
		pinctrl-names = "default";
		pinctrl-0 = <0x9b>;
		power-domains = <0x16 0x1c>;
		status = "disabled";
		assigned-clocks = <0x08 0xb1>;
		assigned-clock-parents = <0x08 0x05>;
	};

	i2s@ff880000 {
		compatible = "rockchip,rk3399-i2s\0rockchip,rk3066-i2s";
		reg = <0x00 0xff880000 0x00 0x1000>;
		rockchip,grf = <0x15>;
		interrupts = <0x00 0x27 0x04 0x00>;
		dmas = <0x9a 0x00 0x9a 0x01>;
		dma-names = "tx\0rx";
		clock-names = "i2s_clk\0i2s_hclk";
		clocks = <0x08 0x56 0x08 0x1d4>;
		pinctrl-names = "default";
		pinctrl-0 = <0x9c>;
		power-domains = <0x16 0x1c>;
		status = "okay";
		rockchip,i2s-broken-burst-len;
		rockchip,playback-channels = <0x08>;
		rockchip,capture-channels = <0x08>;
		#sound-dai-cells = <0x00>;
		assigned-clocks = <0x08 0xae>;
		assigned-clock-parents = <0x08 0x05>;
		phandle = <0xd9>;
	};

	i2s@ff890000 {
		compatible = "rockchip,rk3399-i2s\0rockchip,rk3066-i2s";
		reg = <0x00 0xff890000 0x00 0x1000>;
		interrupts = <0x00 0x28 0x04 0x00>;
		dmas = <0x9a 0x02 0x9a 0x03>;
		dma-names = "tx\0rx";
		clock-names = "i2s_clk\0i2s_hclk";
		clocks = <0x08 0x57 0x08 0x1d5>;
		pinctrl-names = "default";
		pinctrl-0 = <0x9d>;
		power-domains = <0x16 0x1c>;
		status = "okay";
		rockchip,i2s-broken-burst-len;
		rockchip,playback-channels = <0x02>;
		rockchip,capture-channels = <0x02>;
		#sound-dai-cells = <0x00>;
		assigned-clocks = <0x08 0x109>;
		assigned-clock-parents = <0x08 0x57>;
		phandle = <0xd6>;
	};

	i2s@ff8a0000 {
		compatible = "rockchip,rk3399-i2s\0rockchip,rk3066-i2s";
		reg = <0x00 0xff8a0000 0x00 0x1000>;
		interrupts = <0x00 0x29 0x04 0x00>;
		dmas = <0x9a 0x04 0x9a 0x05>;
		dma-names = "tx\0rx";
		clock-names = "i2s_clk\0i2s_hclk";
		clocks = <0x08 0x58 0x08 0x1d6>;
		power-domains = <0x16 0x1c>;
		status = "okay";
		#sound-dai-cells = <0x00>;
		assigned-clocks = <0x08 0xb0>;
		assigned-clock-parents = <0x08 0x05>;
		rockchip,bclk-fs = <0x80>;
		phandle = <0xe1>;
	};

	gpu@ff9a0000 {
		compatible = "arm,malit860\0arm,malit86x\0arm,malit8xx\0arm,mali-midgard";
		reg = <0x00 0xff9a0000 0x00 0x10000>;
		interrupts = <0x00 0x13 0x04 0x00 0x00 0x14 0x04 0x00 0x00 0x15 0x04 0x00>;
		interrupt-names = "GPU\0JOB\0MMU";
		clocks = <0x08 0xd0>;
		clock-names = "clk_mali";
		#cooling-cells = <0x02>;
		power-domains = <0x16 0x23>;
		power-off-delay-ms = <0xc8>;
		status = "okay";
		operating-points-v2 = <0x9e>;
		mali-supply = <0x9f>;
		phandle = <0x65>;

		power_model {
			compatible = "arm,mali-simple-power-model";
			static-coefficient = <0x64578>;
			dynamic-coefficient = <0x2dd>;
			ts = <0x7d00 0x125c 0xffffffb0 0x02>;
			thermal-zone = "gpu-thermal";
		};
	};

	vop@ff8f0000 {
		compatible = "rockchip,rk3399-vop-lit";
		reg = <0x00 0xff8f0000 0x00 0x600 0x00 0xff8f1c00 0x00 0x200 0x00 0xff8f2000 0x00 0x400>;
		reg-names = "regs\0cabc_lut\0gamma_lut";
		interrupts = <0x00 0x77 0x04 0x00>;
		clocks = <0x08 0xdb 0x08 0xb5 0x08 0x1db 0x08 0xb7>;
		clock-names = "aclk_vop\0dclk_vop\0hclk_vop\0dclk_source";
		resets = <0x08 0x113 0x08 0x117 0x08 0x119>;
		reset-names = "axi\0ahb\0dclk";
		power-domains = <0x16 0x12>;
		iommus = <0xa0>;
		status = "okay";

		port {
			#address-cells = <0x01>;
			#size-cells = <0x00>;
			phandle = <0xbf>;

			endpoint@0 {
				reg = <0x00>;
				remote-endpoint = <0xa1>;
				phandle = <0xb6>;
			};

			endpoint@1 {
				reg = <0x01>;
				remote-endpoint = <0xa2>;
				phandle = <0xbd>;
			};

			endpoint@2 {
				reg = <0x02>;
				remote-endpoint = <0xa3>;
				phandle = <0xb4>;
			};

			endpoint@3 {
				reg = <0x03>;
				remote-endpoint = <0xa4>;
				phandle = <0x30>;
			};

			endpoint@4 {
				reg = <0x04>;
				remote-endpoint = <0xa5>;
				phandle = <0xba>;
			};
		};
	};

	voppwm@ff8f01a0 {
		compatible = "rockchip,vop-pwm";
		reg = <0x00 0xff8f01a0 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0xa6>;
		clocks = <0x08 0x6c>;
		clock-names = "pwm";
		status = "disabled";
	};

	iommu@ff8f3f00 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff8f3f00 0x00 0x100>;
		interrupts = <0x00 0x77 0x04 0x00>;
		interrupt-names = "vopl_mmu";
		clocks = <0x08 0xdb 0x08 0x1db>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x12>;
		#iommu-cells = <0x00>;
		status = "okay";
		phandle = <0xa0>;
	};

	vop@ff900000 {
		compatible = "rockchip,rk3399-vop-big";
		reg = <0x00 0xff900000 0x00 0x600 0x00 0xff901c00 0x00 0x200 0x00 0xff902000 0x00 0x1000>;
		reg-names = "regs\0cabc_lut\0gamma_lut";
		interrupts = <0x00 0x76 0x04 0x00>;
		clocks = <0x08 0xd9 0x08 0xb4 0x08 0x1d9 0x08 0xb6>;
		clock-names = "aclk_vop\0dclk_vop\0hclk_vop\0dclk_source";
		resets = <0x08 0x112 0x08 0x116 0x08 0x118>;
		reset-names = "axi\0ahb\0dclk";
		power-domains = <0x16 0x11>;
		iommus = <0xa7>;
		status = "okay";

		port {
			#address-cells = <0x01>;
			#size-cells = <0x00>;
			phandle = <0xbe>;

			endpoint@0 {
				reg = <0x00>;
				remote-endpoint = <0xa8>;
				phandle = <0xbc>;
			};

			endpoint@1 {
				reg = <0x01>;
				remote-endpoint = <0xa9>;
				phandle = <0xb5>;
			};

			endpoint@2 {
				reg = <0x02>;
				remote-endpoint = <0xaa>;
				phandle = <0xb3>;
			};

			endpoint@3 {
				reg = <0x03>;
				remote-endpoint = <0xab>;
				phandle = <0x2f>;
			};

			endpoint@4 {
				reg = <0x04>;
				remote-endpoint = <0xac>;
				phandle = <0xb9>;
			};
		};
	};

	voppwm@ff9001a0 {
		compatible = "rockchip,vop-pwm";
		reg = <0x00 0xff9001a0 0x00 0x10>;
		#pwm-cells = <0x03>;
		pinctrl-names = "active";
		pinctrl-0 = <0xad>;
		clocks = <0x08 0x6b>;
		clock-names = "pwm";
		status = "disabled";
	};

	iommu@ff903f00 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff903f00 0x00 0x100>;
		interrupts = <0x00 0x76 0x04 0x00>;
		interrupt-names = "vopb_mmu";
		clocks = <0x08 0xd9 0x08 0x1d9>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x11>;
		#iommu-cells = <0x00>;
		status = "okay";
		phandle = <0xa7>;
	};

	rkisp1@ff910000 {
		compatible = "rockchip,rk3399-rkisp1";
		reg = <0x00 0xff910000 0x00 0x4000>;
		interrupts = <0x00 0x2b 0x04 0x00>;
		clocks = <0x08 0x6e 0x08 0xe5 0x08 0x1df 0x08 0xe9 0x08 0x1e3>;
		clock-names = "clk_isp\0aclk_isp\0hclk_isp\0aclk_isp_wrap\0hclk_isp_wrap";
		devfreq = <0xae>;
		power-domains = <0x16 0x13>;
		iommus = <0xaf>;
		status = "disabled";
	};

	iommu@ff914000 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff914000 0x00 0x100 0x00 0xff915000 0x00 0x100>;
		interrupts = <0x00 0x2b 0x04 0x00>;
		interrupt-names = "isp0_mmu";
		#iommu-cells = <0x00>;
		clocks = <0x08 0xe9 0x08 0x1e3>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x13>;
		rk_iommu,disable_reset_quirk;
		status = "okay";
		phandle = <0xaf>;
	};

	rkisp1@ff920000 {
		compatible = "rockchip,rk3399-rkisp1";
		reg = <0x00 0xff920000 0x00 0x4000>;
		interrupts = <0x00 0x2c 0x04 0x00>;
		clocks = <0x08 0x6f 0x08 0xe6 0x08 0x1e0 0x08 0xea 0x08 0x1e4 0x08 0x17b>;
		clock-names = "clk_isp\0aclk_isp\0hclk_isp\0aclk_isp_wrap\0hclk_isp_wrap\0pclk_isp_wrap";
		devfreq = <0xae>;
		power-domains = <0x16 0x14>;
		iommus = <0xb0>;
		status = "disabled";
	};

	iommu@ff924000 {
		compatible = "rockchip,iommu";
		reg = <0x00 0xff924000 0x00 0x100 0x00 0xff925000 0x00 0x100>;
		interrupts = <0x00 0x2c 0x04 0x00>;
		interrupt-names = "isp1_mmu";
		#iommu-cells = <0x00>;
		clocks = <0x08 0xea 0x08 0x1e4>;
		clock-names = "aclk\0hclk";
		power-domains = <0x16 0x14>;
		rk_iommu,disable_reset_quirk;
		status = "okay";
		phandle = <0xb0>;
	};

	hdmi@ff940000 {
		compatible = "rockchip,rk3399-dw-hdmi";
		reg = <0x00 0xff940000 0x00 0x20000>;
		reg-io-width = <0x04>;
		rockchip,grf = <0x15>;
		pinctrl-names = "default";
		pinctrl-0 = <0xb1 0xb2>;
		power-domains = <0x16 0x15>;
		interrupts = <0x00 0x17 0x04 0x00>;
		clocks = <0x08 0x174 0x08 0x71 0x08 0x07 0x08 0x16f 0x08 0x70>;
		clock-names = "iahb\0isfr\0vpll\0grf\0cec";
		status = "okay";
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		#sound-dai-cells = <0x00>;
		ddc-i2c-scl-high-time-ns = <0x2599>;
		ddc-i2c-scl-low-time-ns = <0x2710>;
		phandle = <0xe2>;

		ports {

			port {
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				endpoint@0 {
					reg = <0x00>;
					remote-endpoint = <0xb3>;
					phandle = <0xaa>;
				};

				endpoint@1 {
					reg = <0x01>;
					remote-endpoint = <0xb4>;
					phandle = <0xa3>;
				};
			};
		};
	};

	dsi@ff960000 {
		compatible = "rockchip,rk3399-mipi-dsi";
		reg = <0x00 0xff960000 0x00 0x8000>;
		interrupts = <0x00 0x2d 0x04 0x00>;
		clocks = <0x08 0xa2 0x08 0x170 0x08 0xa3>;
		clock-names = "ref\0pclk\0phy_cfg";
		resets = <0x08 0xfb>;
		reset-names = "apb";
		power-domains = <0x16 0x0f>;
		rockchip,grf = <0x15>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "okay";

		ports {

			port {
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				endpoint@0 {
					reg = <0x00>;
					remote-endpoint = <0xb5>;
					status = "okay";
					phandle = <0xa9>;
				};

				endpoint@1 {
					reg = <0x01>;
					remote-endpoint = <0xb6>;
					status = "okay";
					phandle = <0xa1>;
				};
			};
		};

		panel@0 {
			compatible = "sitronix,st7703\0simple-panel-dsi";
			status = "okay";
			reg = <0x00>;
			backlight = <0xb7>;
			prepare-delay-ms = <0x02>;
			reset-delay-ms = <0x01>;
			init-delay-ms = <0x14>;
			enable-delay-ms = <0x78>;
			disable-delay-ms = <0x32>;
			unprepare-delay-ms = <0x14>;
			enable-gpios = <0x35 0x0d 0x00>;
			width-mm = <0x44>;
			height-mm = <0x79>;
			dsi,flags = <0xa03>;
			dsi,format = <0x00>;
			dsi,lanes = <0x04>;
			panel-init-sequence = [05 fa 01 11 39 00 04 b9 f1 12 83 39 00 1c ba 33 81 05 f9 0e 0e 00 00 00 00 00 00 00 00 44 25 00 91 0a 00 00 02 4f 01 00 00 37 15 00 02 b8 25 39 00 04 bf 02 11 00 39 00 0b b3 0c 10 0a 50 03 ff 00 00 00 00 39 00 0a c0 73 73 50 50 00 00 08 70 00 15 00 02 bc 46 15 00 02 cc 0b 15 00 02 b4 80 39 00 04 b2 c8 12 30 39 00 0f e3 07 07 0b 0b 03 0b 00 00 00 00 ff 00 c0 10 39 00 0d c1 53 00 1e 1e 77 e1 cc dd 67 77 33 33 39 00 07 c6 00 00 ff ff 01 ff 39 00 03 b5 09 09 39 00 03 b6 87 95 39 00 40 e9 c2 10 05 05 10 05 a0 12 31 23 3f 81 0a a0 37 18 00 80 01 00 00 00 00 80 01 00 00 00 48 f8 86 42 08 88 88 80 88 88 88 58 f8 87 53 18 88 88 81 88 88 88 00 00 00 01 00 00 00 00 00 00 00 00 00 39 00 3e ea 00 1a 00 00 00 00 02 00 00 00 00 00 1f 88 81 35 78 88 88 85 88 88 88 0f 88 80 24 68 88 88 84 88 88 88 23 10 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 30 05 a0 00 00 00 00 39 00 23 e0 00 06 08 2a 31 3f 38 36 07 0c 0d 11 13 12 13 11 18 00 06 08 2a 31 3f 38 36 07 0c 0d 11 13 12 13 11 18 05 32 01 29];
			panel-exit-sequence = <0x5000128 0x5000110>;

			display-timings {
				native-mode = <0xb8>;

				timing0 {
					clock-frequency = <0x3d09000>;
					hactive = <0x2d0>;
					vactive = <0x500>;
					hfront-porch = <0x28>;
					hsync-len = <0x0a>;
					hback-porch = <0x28>;
					vfront-porch = <0x16>;
					vsync-len = <0x04>;
					vback-porch = <0x0b>;
					hsync-active = <0x00>;
					vsync-active = <0x00>;
					de-active = <0x00>;
					pixelclk-active = <0x00>;
					phandle = <0xb8>;
				};
			};
		};
	};

	dsi@ff968000 {
		compatible = "rockchip,rk3399-mipi-dsi";
		reg = <0x00 0xff968000 0x00 0x8000>;
		interrupts = <0x00 0x2e 0x04 0x00>;
		clocks = <0x08 0xa2 0x08 0x171 0x08 0xa4>;
		clock-names = "ref\0pclk\0phy_cfg";
		resets = <0x08 0xfc>;
		reset-names = "apb";
		power-domains = <0x16 0x0f>;
		rockchip,grf = <0x15>;
		#address-cells = <0x01>;
		#size-cells = <0x00>;
		status = "disabled";

		ports {

			port {
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				endpoint@0 {
					reg = <0x00>;
					remote-endpoint = <0xb9>;
					phandle = <0xac>;
				};

				endpoint@1 {
					reg = <0x01>;
					remote-endpoint = <0xba>;
					phandle = <0xa5>;
				};
			};
		};
	};

	mipi-dphy-tx1rx1@0xff968000 {
		compatible = "rockchip,rk3399-mipi-dphy";
		reg = <0x00 0xff968000 0x00 0x8000>;
		clocks = <0x08 0x77 0x08 0xa4 0x08 0x16f 0x08 0x171>;
		clock-names = "dphy-ref\0dphy-cfg\0grf\0pclk_mipi_dsi";
		rockchip,grf = <0x15>;
		power-domains = <0x16 0x0f>;
		status = "disabled";
	};

	edp@ff970000 {
		compatible = "rockchip,rk3399-edp";
		reg = <0x00 0xff970000 0x00 0x8000>;
		interrupts = <0x00 0x0a 0x04 0x00>;
		clocks = <0x08 0x16a 0x08 0x16c>;
		clock-names = "dp\0pclk";
		power-domains = <0x16 0x19>;
		resets = <0x08 0x11d>;
		reset-names = "dp";
		rockchip,grf = <0x15>;
		status = "disabled";
		pinctrl-names = "default";
		pinctrl-0 = <0xbb>;

		ports {
			#address-cells = <0x01>;
			#size-cells = <0x00>;

			port@0 {
				reg = <0x00>;
				#address-cells = <0x01>;
				#size-cells = <0x00>;

				endpoint@0 {
					reg = <0x00>;
					remote-endpoint = <0xbc>;
					phandle = <0xa8>;
				};

				endpoint@1 {
					reg = <0x01>;
					remote-endpoint = <0xbd>;
					phandle = <0xa2>;
				};
			};
		};
	};

	hdmi-hdcp2@ff988000 {
		compatible = "rockchip,rk3399-hdmi-hdcp2";
		reg = <0x00 0xff988000 0x00 0x2000>;
		interrupts = <0x00 0x16 0x04 0x00>;
		clocks = <0x08 0xe0 0x08 0x176 0x08 0x1e9>;
		clock-names = "aclk_hdcp2\0pclk_hdcp2\0hdcp2_clk_hdmi";
		status = "disabled";
	};

	display-subsystem {
		compatible = "rockchip,display-subsystem";
		ports = <0xbe 0xbf>;
		clocks = <0x08 0x07 0x08 0x04>;
		clock-names = "hdmi-tmds-pll\0default-vop-pll";
		devfreq = <0xae>;
		status = "okay";
		logo-memory-region = <0xc0>;
		secure-memory-region = <0xc1>;

		route {

			route-hdmi {
				status = "disabled";
				logo,uboot = "logo.bmp";
				logo,kernel = "logo_kernel.bmp";
				logo,mode = "center";
				charge_logo,mode = "center";
				connect = <0xb3>;
			};

			route-dsi {
				status = "okay";
				logo,uboot = "logo.bmp";
				logo,kernel = "logo_kernel.bmp";
				logo,mode = "center";
				charge_logo,mode = "center";
				connect = <0xb5>;
			};

			route-dsi1 {
				status = "disabled";
				logo,uboot = "logo.bmp";
				logo,kernel = "logo_kernel.bmp";
				logo,mode = "center";
				charge_logo,mode = "center";
				connect = <0xba>;
			};

			route-edp {
				status = "disabled";
				logo,uboot = "logo.bmp";
				logo,kernel = "logo_kernel.bmp";
				logo,mode = "center";
				charge_logo,mode = "center";
				connect = <0xbc>;
			};
		};
	};

	nocp-cci-msch0@ffa86000 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa86000 0x00 0x400>;
	};

	nocp-gpu-msch0@ffa86400 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa86400 0x00 0x400>;
	};

	nocp-hp-msch0@ffa86800 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa86800 0x00 0x400>;
	};

	nocp-lp-msch0@ffa86c00 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa86c00 0x00 0x400>;
	};

	nocp-video-msch0@ffa87000 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa87000 0x00 0x400>;
	};

	nocp-vio0-msch0@ffa87400 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa87400 0x00 0x400>;
	};

	nocp-vio1-msch0@ffa87800 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa87800 0x00 0x400>;
	};

	nocp-cci-msch1@ffa8e000 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8e000 0x00 0x400>;
	};

	nocp-gpu-msch1@ffa8e400 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8e400 0x00 0x400>;
	};

	nocp-hp-msch1@ffa8e800 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8e800 0x00 0x400>;
	};

	nocp-lp-msch1@ffa8ec00 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8ec00 0x00 0x400>;
	};

	nocp-video-msch1@ffa8f000 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8f000 0x00 0x400>;
	};

	nocp-vio0-msch1@ffa8f400 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8f400 0x00 0x400>;
	};

	nocp-vio1-msch1@ffa8f800 {
		compatible = "rockchip,rk3399-nocp";
		reg = <0x00 0xffa8f800 0x00 0x400>;
	};

	pinctrl {
		compatible = "rockchip,rk3399-pinctrl";
		rockchip,grf = <0x15>;
		rockchip,pmu = <0x90>;
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;

		gpio0@ff720000 {
			compatible = "rockchip,gpio-bank";
			reg = <0x00 0xff720000 0x00 0x100>;
			clocks = <0x31 0x17>;
			interrupts = <0x00 0x0e 0x04 0x00>;
			gpio-controller;
			#gpio-cells = <0x02>;
			interrupt-controller;
			#interrupt-cells = <0x02>;
			phandle = <0x3c>;
		};

		gpio1@ff730000 {
			compatible = "rockchip,gpio-bank";
			reg = <0x00 0xff730000 0x00 0x100>;
			clocks = <0x31 0x18>;
			interrupts = <0x00 0x0f 0x04 0x00>;
			gpio-controller;
			#gpio-cells = <0x02>;
			interrupt-controller;
			#interrupt-cells = <0x02>;
			phandle = <0x35>;
		};

		gpio2@ff780000 {
			compatible = "rockchip,gpio-bank";
			reg = <0x00 0xff780000 0x00 0x100>;
			clocks = <0x08 0x150>;
			interrupts = <0x00 0x10 0x04 0x00>;
			gpio-controller;
			#gpio-cells = <0x02>;
			interrupt-controller;
			#interrupt-cells = <0x02>;
			phandle = <0xcf>;
		};

		gpio3@ff788000 {
			compatible = "rockchip,gpio-bank";
			reg = <0x00 0xff788000 0x00 0x100>;
			clocks = <0x08 0x151>;
			interrupts = <0x00 0x11 0x04 0x00>;
			gpio-controller;
			#gpio-cells = <0x02>;
			interrupt-controller;
			#interrupt-cells = <0x02>;
			phandle = <0x18>;
		};

		gpio4@ff790000 {
			compatible = "rockchip,gpio-bank";
			reg = <0x00 0xff790000 0x00 0x100>;
			clocks = <0x08 0x152>;
			interrupts = <0x00 0x12 0x04 0x00>;
			gpio-controller;
			#gpio-cells = <0x02>;
			interrupt-controller;
			#interrupt-cells = <0x02>;
			phandle = <0x3d>;
		};

		pcfg-pull-up {
			bias-pull-up;
			phandle = <0xc2>;
		};

		pcfg-pull-down {
			bias-pull-down;
			phandle = <0xc6>;
		};

		pcfg-pull-none {
			bias-disable;
			phandle = <0xc4>;
		};

		pcfg-pull-up-20ma {
			bias-pull-up;
			drive-strength = <0x14>;
		};

		pcfg-pull-none-20ma {
			bias-disable;
			drive-strength = <0x14>;
		};

		pcfg-pull-none-18ma {
			bias-disable;
			drive-strength = <0x12>;
		};

		pcfg-pull-none-12ma {
			bias-disable;
			drive-strength = <0x0c>;
			phandle = <0xc5>;
		};

		pcfg-pull-up-8ma {
			bias-pull-up;
			drive-strength = <0x08>;
		};

		pcfg-pull-down-4ma {
			bias-pull-down;
			drive-strength = <0x04>;
		};

		pcfg-pull-up-2ma {
			bias-pull-up;
			drive-strength = <0x02>;
		};

		pcfg-pull-down-12ma {
			bias-pull-down;
			drive-strength = <0x0c>;
		};

		pcfg-pull-none-13ma {
			bias-disable;
			drive-strength = <0x0d>;
			phandle = <0xc3>;
		};

		pcfg-output-high {
			output-high;
		};

		pcfg-output-low {
			output-low;
		};

		pcfg-input {
			input-enable;
		};

		emmc {

			emmc-pwr {
				rockchip,pins = <0x00 0x05 0x01 0xc2>;
			};
		};

		gmac {

			rgmii-pins {
				rockchip,pins = <0x03 0x11 0x01 0xc3 0x03 0x0e 0x01 0xc4 0x03 0x0d 0x01 0xc4 0x03 0x0c 0x01 0xc3 0x03 0x0b 0x01 0xc4 0x03 0x09 0x01 0xc4 0x03 0x08 0x01 0xc4 0x03 0x07 0x01 0xc4 0x03 0x06 0x01 0xc4 0x03 0x05 0x01 0xc3 0x03 0x04 0x01 0xc3 0x03 0x03 0x01 0xc4 0x03 0x02 0x01 0xc4 0x03 0x01 0x01 0xc3 0x03 0x00 0x01 0xc3>;
				phandle = <0x1a>;
			};

			rmii-pins {
				rockchip,pins = <0x03 0x0d 0x01 0xc4 0x03 0x0c 0x01 0xc3 0x03 0x0b 0x01 0xc4 0x03 0x0a 0x01 0xc4 0x03 0x09 0x01 0xc4 0x03 0x08 0x01 0xc4 0x03 0x07 0x01 0xc4 0x03 0x06 0x01 0xc4 0x03 0x05 0x01 0xc3 0x03 0x04 0x01 0xc3>;
			};
		};

		i2c0 {

			i2c0-xfer {
				rockchip,pins = <0x01 0x0f 0x02 0xc4 0x01 0x10 0x02 0xc4>;
				phandle = <0x32>;
			};
		};

		i2c1 {

			i2c1-xfer {
				rockchip,pins = <0x04 0x02 0x01 0xc4 0x04 0x01 0x01 0xc4>;
				phandle = <0x3a>;
			};
		};

		i2c2 {

			i2c2-xfer {
				rockchip,pins = <0x02 0x01 0x02 0xc5 0x02 0x00 0x02 0xc5>;
				phandle = <0x43>;
			};
		};

		i2c3 {

			i2c3-xfer {
				rockchip,pins = <0x04 0x11 0x01 0xc4 0x04 0x10 0x01 0xc4>;
				phandle = <0x44>;
			};

			i2c3_gpio {
				rockchip,pins = <0x04 0x11 0x00 0xc4 0x04 0x10 0x00 0xc4>;
			};
		};

		i2c4 {

			i2c4-xfer {
				rockchip,pins = <0x01 0x0c 0x01 0xc4 0x01 0x0b 0x01 0xc4>;
				phandle = <0x86>;
			};
		};

		i2c5 {

			i2c5-xfer {
				rockchip,pins = <0x03 0x0b 0x02 0xc4 0x03 0x0a 0x02 0xc4>;
				phandle = <0x45>;
			};
		};

		i2c6 {

			i2c6-xfer {
				rockchip,pins = <0x02 0x0a 0x02 0xc4 0x02 0x09 0x02 0xc4>;
				phandle = <0x46>;
			};
		};

		i2c7 {

			i2c7-xfer {
				rockchip,pins = <0x02 0x08 0x02 0xc4 0x02 0x07 0x02 0xc4>;
				phandle = <0x47>;
			};
		};

		i2c8 {

			i2c8-xfer {
				rockchip,pins = <0x01 0x15 0x01 0xc4 0x01 0x14 0x01 0xc4>;
				phandle = <0x88>;
			};
		};

		i2s0 {

			i2s0-8ch-bus {
				rockchip,pins = <0x03 0x18 0x01 0xc4 0x03 0x19 0x01 0xc4 0x03 0x1a 0x01 0xc4 0x03 0x1b 0x01 0xc4 0x03 0x1c 0x01 0xc4 0x03 0x1d 0x01 0xc4 0x03 0x1e 0x01 0xc4 0x03 0x1f 0x01 0xc4>;
				phandle = <0x9c>;
			};

			i2s-8ch-mclk {
				rockchip,pins = <0x04 0x00 0x01 0xc4>;
				phandle = <0x3b>;
			};
		};

		i2s1 {

			i2s1-2ch-bus {
				rockchip,pins = <0x04 0x03 0x01 0xc4 0x04 0x04 0x01 0xc4 0x04 0x05 0x01 0xc4 0x04 0x06 0x01 0xc4 0x04 0x07 0x01 0xc4>;
				phandle = <0x9d>;
			};
		};

		sdio0 {

			sdio0-bus1 {
				rockchip,pins = <0x02 0x14 0x01 0xc2>;
			};

			sdio0-bus4 {
				rockchip,pins = <0x02 0x14 0x01 0xc2 0x02 0x15 0x01 0xc2 0x02 0x16 0x01 0xc2 0x02 0x17 0x01 0xc2>;
				phandle = <0x1c>;
			};

			sdio0-cmd {
				rockchip,pins = <0x02 0x18 0x01 0xc2>;
				phandle = <0x1d>;
			};

			sdio0-clk {
				rockchip,pins = <0x02 0x19 0x01 0xc4>;
				phandle = <0x1e>;
			};

			sdio0-cd {
				rockchip,pins = <0x02 0x1a 0x01 0xc2>;
			};

			sdio0-pwr {
				rockchip,pins = <0x02 0x1b 0x01 0xc2>;
			};

			sdio0-bkpwr {
				rockchip,pins = <0x02 0x1c 0x01 0xc2>;
			};

			sdio0-wp {
				rockchip,pins = <0x00 0x03 0x01 0xc2>;
			};

			sdio0-int {
				rockchip,pins = <0x00 0x04 0x01 0xc2>;
			};
		};

		sdmmc {

			sdmmc-bus1 {
				rockchip,pins = <0x04 0x08 0x01 0xc2>;
			};

			sdmmc-bus4 {
				rockchip,pins = <0x04 0x08 0x01 0xc2 0x04 0x09 0x01 0xc2 0x04 0x0a 0x01 0xc2 0x04 0x0b 0x01 0xc2>;
				phandle = <0x24>;
			};

			sdmmc-clk {
				rockchip,pins = <0x04 0x0c 0x01 0xc4>;
				phandle = <0x21>;
			};

			sdmmc-cmd {
				rockchip,pins = <0x04 0x0d 0x01 0xc2>;
				phandle = <0x22>;
			};

			sdmcc-cd {
				rockchip,pins = <0x00 0x07 0x01 0xc2>;
				phandle = <0x23>;
			};

			sdmmc-wp {
				rockchip,pins = <0x00 0x08 0x01 0xc2>;
			};
		};

		spdif {

			spdif-bus {
				rockchip,pins = <0x04 0x15 0x01 0xc4>;
				phandle = <0x9b>;
			};

			spdif-bus-1 {
				rockchip,pins = <0x03 0x10 0x03 0xc4>;
			};
		};

		spi0 {

			spi0-clk {
				rockchip,pins = <0x03 0x06 0x02 0xc2>;
				phandle = <0x4f>;
			};

			spi0-cs0 {
				rockchip,pins = <0x03 0x07 0x02 0xc2>;
				phandle = <0x52>;
			};

			spi0-cs1 {
				rockchip,pins = <0x03 0x08 0x02 0xc2>;
			};

			spi0-tx {
				rockchip,pins = <0x03 0x05 0x02 0xc2>;
				phandle = <0x50>;
			};

			spi0-rx {
				rockchip,pins = <0x03 0x04 0x02 0xc2>;
				phandle = <0x51>;
			};
		};

		spi1 {

			spi1-clk {
				rockchip,pins = <0x01 0x09 0x02 0xc2>;
				phandle = <0x53>;
			};

			spi1-cs0 {
				rockchip,pins = <0x01 0x0a 0x02 0xc2>;
				phandle = <0x56>;
			};

			spi1-rx {
				rockchip,pins = <0x01 0x07 0x02 0xc2>;
				phandle = <0x55>;
			};

			spi1-tx {
				rockchip,pins = <0x01 0x08 0x02 0xc2>;
				phandle = <0x54>;
			};
		};

		spi2 {

			spi2-clk {
				rockchip,pins = <0x02 0x0b 0x01 0xc2>;
				phandle = <0x57>;
			};

			spi2-cs0 {
				rockchip,pins = <0x02 0x0c 0x01 0xc2>;
				phandle = <0x5a>;
			};

			spi2-rx {
				rockchip,pins = <0x02 0x09 0x01 0xc2>;
				phandle = <0x59>;
			};

			spi2-tx {
				rockchip,pins = <0x02 0x0a 0x01 0xc2>;
				phandle = <0x58>;
			};
		};

		spi3 {

			spi3-clk {
				rockchip,pins = <0x01 0x11 0x01 0xc2>;
				phandle = <0x81>;
			};

			spi3-cs0 {
				rockchip,pins = <0x01 0x12 0x01 0xc2>;
				phandle = <0x84>;
			};

			spi3-rx {
				rockchip,pins = <0x01 0x0f 0x01 0xc2>;
				phandle = <0x83>;
			};

			spi3-tx {
				rockchip,pins = <0x01 0x10 0x01 0xc2>;
				phandle = <0x82>;
			};
		};

		spi4 {

			spi4-clk {
				rockchip,pins = <0x03 0x02 0x02 0xc2>;
				phandle = <0x5b>;
			};

			spi4-cs0 {
				rockchip,pins = <0x03 0x03 0x02 0xc2>;
				phandle = <0x5e>;
			};

			spi4-rx {
				rockchip,pins = <0x03 0x00 0x02 0xc2>;
				phandle = <0x5d>;
			};

			spi4-tx {
				rockchip,pins = <0x03 0x01 0x02 0xc2>;
				phandle = <0x5c>;
			};
		};

		spi5 {

			spi5-clk {
				rockchip,pins = <0x02 0x16 0x02 0xc2>;
				phandle = <0x5f>;
			};

			spi5-cs0 {
				rockchip,pins = <0x02 0x17 0x02 0xc2>;
				phandle = <0x62>;
			};

			spi5-rx {
				rockchip,pins = <0x02 0x14 0x02 0xc2>;
				phandle = <0x61>;
			};

			spi5-tx {
				rockchip,pins = <0x02 0x15 0x02 0xc2>;
				phandle = <0x60>;
			};
		};

		tsadc {

			otp-gpio {
				rockchip,pins = <0x01 0x06 0x00 0xc4>;
				phandle = <0x66>;
			};

			otp-out {
				rockchip,pins = <0x01 0x06 0x01 0xc4>;
				phandle = <0x67>;
			};
		};

		uart0 {

			uart0-xfer {
				rockchip,pins = <0x02 0x10 0x01 0xc2 0x02 0x11 0x01 0xc4>;
				phandle = <0x48>;
			};

			uart0-cts {
				rockchip,pins = <0x02 0x12 0x01 0xc4>;
				phandle = <0x49>;
			};

			uart0-rts {
				rockchip,pins = <0x02 0x13 0x01 0xc4>;
				phandle = <0xd0>;
			};
		};

		uart1 {

			uart1-xfer {
				rockchip,pins = <0x03 0x0c 0x02 0xc2 0x03 0x0d 0x02 0xc4>;
				phandle = <0x4a>;
			};
		};

		uart2a {

			uart2a-xfer {
				rockchip,pins = <0x04 0x08 0x02 0xc2 0x04 0x09 0x02 0xc4>;
			};
		};

		uart2b {

			uart2b-xfer {
				rockchip,pins = <0x04 0x10 0x02 0xc2 0x04 0x11 0x02 0xc4>;
			};
		};

		uart2c {

			uart2c-xfer {
				rockchip,pins = <0x04 0x13 0x01 0xc2 0x04 0x14 0x01 0xc4>;
				phandle = <0x4b>;
			};
		};

		uart3 {

			uart3-xfer {
				rockchip,pins = <0x03 0x0e 0x02 0xc2 0x03 0x0f 0x02 0xc4>;
				phandle = <0x4c>;
			};

			uart3-cts {
				rockchip,pins = <0x03 0x12 0x02 0xc4>;
				phandle = <0x4d>;
			};

			uart3-rts {
				rockchip,pins = <0x03 0x13 0x02 0xc4>;
				phandle = <0x4e>;
			};
		};

		uart4 {

			uart4-xfer {
				rockchip,pins = <0x01 0x07 0x01 0xc2 0x01 0x08 0x01 0xc4>;
				phandle = <0x85>;
			};
		};

		uarthdcp {

			uarthdcp-xfer {
				rockchip,pins = <0x04 0x15 0x02 0xc2 0x04 0x16 0x02 0xc4>;
			};
		};

		pwm0 {

			pwm0-pin {
				rockchip,pins = <0x04 0x12 0x01 0xc4>;
				phandle = <0x8c>;
			};

			pwm0-pin-pull-down {
				rockchip,pins = <0x04 0x12 0x01 0xc6>;
			};

			vop0-pwm-pin {
				rockchip,pins = <0x04 0x12 0x02 0xc4>;
				phandle = <0xad>;
			};

			vop1-pwm-pin {
				rockchip,pins = <0x04 0x12 0x03 0xc4>;
				phandle = <0xa6>;
			};
		};

		pwm1 {

			pwm1-pin {
				rockchip,pins = <0x04 0x16 0x01 0xc4>;
				phandle = <0x8d>;
			};

			pwm1-pin-pull-down {
				rockchip,pins = <0x04 0x16 0x01 0xc6>;
			};
		};

		pwm2 {

			pwm2-pin {
				rockchip,pins = <0x01 0x13 0x01 0xc4>;
				phandle = <0x8e>;
			};

			pwm2-pin-pull-down {
				rockchip,pins = <0x01 0x13 0x01 0xc6>;
			};
		};

		pwm3a {

			pwm3a-pin {
				rockchip,pins = <0x00 0x06 0x01 0xc4>;
				phandle = <0x8f>;
			};

			pwm3a-pin-pull-down {
				rockchip,pins = <0x00 0x06 0x01 0xc6>;
			};
		};

		pwm3b {

			pwm3b-pin {
				rockchip,pins = <0x01 0x0e 0x01 0xc4>;
			};

			pwm3b-pin-pull-down {
				rockchip,pins = <0x01 0x0e 0x01 0xc6>;
			};
		};

		edp {

			edp-hpd {
				rockchip,pins = <0x04 0x17 0x02 0xc4>;
				phandle = <0xbb>;
			};
		};

		hdmi {

			hdmi-i2c-xfer {
				rockchip,pins = <0x04 0x11 0x03 0xc4 0x04 0x10 0x03 0xc4>;
				phandle = <0xb1>;
			};

			hdmi-cec {
				rockchip,pins = <0x04 0x17 0x01 0xc4>;
				phandle = <0xb2>;
			};
		};

		pcie {

			pci-clkreqn {
				rockchip,pins = <0x02 0x1a 0x02 0xc4>;
			};

			pci-clkreqnb {
				rockchip,pins = <0x04 0x18 0x01 0xc4>;
			};

			pci-clkreqn-cpm {
				rockchip,pins = <0x02 0x1a 0x00 0xc4>;
			};

			pci-clkreqnb-cpm {
				rockchip,pins = <0x04 0x18 0x00 0xc4>;
			};
		};

		pmic {

			pmic-int-l {
				rockchip,pins = <0x01 0x15 0x00 0xc2>;
				phandle = <0x37>;
			};

			vsel1-gpio {
				rockchip,pins = <0x01 0x11 0x00 0xc6>;
				phandle = <0x34>;
			};

			vsel2-gpio {
				rockchip,pins = <0x01 0x0e 0x00 0xc6>;
				phandle = <0x36>;
			};
		};

		usb {

			host-vbus-drv-usb3 {
				rockchip,pins = <0x00 0x06 0x00 0xc4>;
				phandle = <0xca>;
			};

			host-vbus-drv-usb2 {
				rockchip,pins = <0x00 0x08 0x00 0xc4>;
				phandle = <0xcb>;
			};
		};

		vcc_sd {

			vcc-sd-h {
				rockchip,pins = <0x00 0x01 0x00 0xc2>;
				phandle = <0xcc>;
			};
		};

		fusb30x {

			fusb0-int {
				rockchip,pins = <0x01 0x02 0x00 0xc2>;
				phandle = <0x87>;
			};
		};

		sdio-pwrseq {

			wifi-enable-h {
				rockchip,pins = <0x00 0x0a 0x00 0xc4>;
				phandle = <0xce>;
			};
		};

		wireless-bluetooth {

			uart0-gpios {
				rockchip,pins = <0x02 0x13 0x00 0xc4>;
				phandle = <0xd1>;
			};
		};

		headphone {

			hp-det {
				rockchip,pins = <0x04 0x1c 0x00 0xc2>;
				phandle = <0xd4>;
			};
		};

		gpio-leds {

			leds-gpio {
				rockchip,pins = <0x00 0x02 0x00 0xc2 0x00 0x0c 0x00 0xc2 0x00 0x0d 0x00 0xc2 0x02 0x1b 0x00 0xc2 0x02 0x1c 0x00 0xc2>;
				phandle = <0xd3>;
			};
		};

		isp {

			cif-clkout {
				rockchip,pins = <0x02 0x0b 0x03 0xc4>;
				phandle = <0xdc>;
			};

			isp-dvp-d0d7 {
				rockchip,pins = <0x02 0x00 0x03 0xc4 0x02 0x01 0x03 0xc4 0x02 0x02 0x03 0xc4 0x02 0x03 0x03 0xc4 0x02 0x04 0x03 0xc4 0x02 0x05 0x03 0xc4 0x02 0x06 0x03 0xc4 0x02 0x07 0x03 0xc4 0x02 0x08 0x03 0xc4 0x02 0x09 0x03 0xc4 0x02 0x0a 0x03 0xc4>;
				phandle = <0xdd>;
			};

			isp-shutter {
				rockchip,pins = <0x01 0x01 0x01 0xc4 0x01 0x00 0x01 0xc4>;
			};

			isp-flash-trigger {
				rockchip,pins = <0x01 0x03 0x01 0xc4>;
				phandle = <0xe0>;
			};

			isp-prelight {
				rockchip,pins = <0x01 0x04 0x01 0xc4>;
				phandle = <0xde>;
			};

			isp_flash_trigger_as_gpio {
				rockchip,pins = <0x01 0x03 0x00 0xc4>;
				phandle = <0xdf>;
			};
		};

		vcc_cam {

			vdd-dvdd-pwr-en {
				rockchip,pins = <0x01 0x13 0x00 0xc6>;
				phandle = <0xe6>;
			};

			vdd-dvdd-sel {
				rockchip,pins = <0x04 0x19 0x00 0xc6>;
				phandle = <0xe7>;
			};

			vdd-avdd-pwr-en {
				rockchip,pins = <0x01 0x12 0x00 0xc6>;
				phandle = <0xe8>;
			};
		};

		cam_mclk {

			cam-default-pins {
				rockchip,pins = <0x02 0x0b 0x03 0xc4>;
				phandle = <0x3e>;
			};
		};
	};

	rockchip-suspend {
		compatible = "rockchip,pm-rk3399";
		status = "okay";
		rockchip,sleep-debug-en = <0x01>;
		rockchip,virtual-poweroff = <0x00>;
		rockchip,sleep-mode-config = <0xde>;
		rockchip,wakeup-config = <0x804>;
		rockchip,pwm-regulator-config = <0x04>;
		rockchip,power-ctrl = <0x35 0x11 0x00 0x35 0x0e 0x00>;
	};

	energy-costs {

		rk3399-core-cost0 {
			busy-cost-data = <0x6c 0x2e 0x9f 0x43 0xd8 0x5a 0x10b 0x78 0x13e 0x99 0x177 0xc6 0x191 0xde>;
			idle-cost-data = <0x06 0x06 0x00 0x00>;
			phandle = <0x0c>;
		};

		rk3399-core-cost1 {
			busy-cost-data = <0xd2 0x81 0x134 0xb8 0x1a3 0xf6 0x206 0x14f 0x269 0x1ac 0x2d8 0x23d 0x33b 0x2d4 0x39d 0x384 0x400 0x454>;
			idle-cost-data = <0x0f 0x0f 0x00 0x00>;
			phandle = <0x10>;
		};

		rk3399-cluster-cost0 {
			busy-cost-data = <0x6c 0x2e 0x9f 0x43 0xd8 0x5a 0x10b 0x78 0x13e 0x99 0x177 0xc6 0x191 0xde>;
			idle-cost-data = <0x38 0x38 0x38 0x38>;
			phandle = <0x0d>;
		};

		rk3399-cluster-cost1 {
			busy-cost-data = <0xd2 0x81 0x134 0xb8 0x1a3 0xf6 0x206 0x14f 0x269 0x1ac 0x2d8 0x23d 0x33b 0x2d4 0x39d 0x384 0x400 0x454>;
			idle-cost-data = <0x41 0x41 0x41 0x41>;
			phandle = <0x11>;
		};
	};

	opp-table0 {
		compatible = "operating-points-v2";
		opp-shared;
		nvmem-cells = <0xc7>;
		nvmem-cell-names = "cpu_leakage";
		rockchip,pvtm-voltage-sel = <0x00 0x2308c 0x00 0x2308d 0x24414 0x01 0x24415 0x251c0 0x02 0x251c1 0xf423f 0x03>;
		rockchip,pvtm-freq = <0x639c0>;
		rockchip,pvtm-volt = <0xf4240>;
		rockchip,pvtm-ch = <0x00 0x00>;
		rockchip,pvtm-sample-time = <0x3e8>;
		rockchip,pvtm-number = <0x0a>;
		rockchip,pvtm-error = <0x3e8>;
		rockchip,pvtm-ref-temp = <0x29>;
		rockchip,pvtm-temp-prop = <0x73 0x42>;
		rockchip,pvtm-thermal-zone = "soc-thermal";
		phandle = <0x0b>;

		opp-408000000 {
			opp-hz = <0x00 0x18519600>;
			opp-microvolt = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L0 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L1 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-600000000 {
			opp-hz = <0x00 0x23c34600>;
			opp-microvolt = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L0 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L1 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-816000000 {
			opp-hz = <0x00 0x30a32c00>;
			opp-microvolt = <0xcf850 0xcf850 0x124f80>;
			opp-microvolt-L0 = <0xcf850 0xcf850 0x124f80>;
			opp-microvolt-L1 = <0xc96a8 0xc96a8 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
			opp-suspend;
		};

		opp-1008000000 {
			opp-hz = <0x00 0x3c14dc00>;
			opp-microvolt = <0xe1d48 0xe1d48 0x124f80>;
			opp-microvolt-L0 = <0xe1d48 0xe1d48 0x124f80>;
			opp-microvolt-L1 = <0xdbba0 0xdbba0 0x124f80>;
			opp-microvolt-L2 = <0xd59f8 0xd59f8 0x124f80>;
			opp-microvolt-L3 = <0xcf850 0xcf850 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1200000000 {
			opp-hz = <0x00 0x47868c00>;
			opp-microvolt = <0xf4240 0xf4240 0x124f80>;
			opp-microvolt-L0 = <0xf4240 0xf4240 0x124f80>;
			opp-microvolt-L1 = <0xee098 0xee098 0x124f80>;
			opp-microvolt-L2 = <0xe7ef0 0xe7ef0 0x124f80>;
			opp-microvolt-L3 = <0xe1d48 0xe1d48 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1416000000 {
			opp-hz = <0x00 0x54667200>;
			opp-microvolt = <0x112a88 0x112a88 0x124f80>;
			opp-microvolt-L0 = <0x112a88 0x112a88 0x124f80>;
			opp-microvolt-L1 = <0x10c8e0 0x10c8e0 0x124f80>;
			opp-microvolt-L2 = <0x106738 0x106738 0x124f80>;
			opp-microvolt-L3 = <0x100590 0x100590 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};
	};

	opp-table1 {
		compatible = "operating-points-v2";
		opp-shared;
		nvmem-cells = <0xc8>;
		nvmem-cell-names = "cpu_leakage";
		rockchip,pvtm-voltage-sel = <0x00 0x24608 0x00 0x24609 0x25d78 0x01 0x25d79 0x27100 0x02 0x27101 0xf423f 0x03>;
		rockchip,pvtm-freq = <0x639c0>;
		rockchip,pvtm-volt = <0xf4240>;
		rockchip,pvtm-ch = <0x01 0x00>;
		rockchip,pvtm-sample-time = <0x3e8>;
		rockchip,pvtm-number = <0x0a>;
		rockchip,pvtm-error = <0x3e8>;
		rockchip,pvtm-ref-temp = <0x29>;
		rockchip,pvtm-temp-prop = <0x47 0x23>;
		rockchip,pvtm-thermal-zone = "soc-thermal";
		phandle = <0x0f>;

		opp-408000000 {
			opp-hz = <0x00 0x18519600>;
			opp-microvolt = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L0 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L1 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-600000000 {
			opp-hz = <0x00 0x23c34600>;
			opp-microvolt = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L0 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L1 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-816000000 {
			opp-hz = <0x00 0x30a32c00>;
			opp-microvolt = <0xc96a8 0xc96a8 0x124f80>;
			opp-microvolt-L0 = <0xc96a8 0xc96a8 0x124f80>;
			opp-microvolt-L1 = <0xc96a8 0xc96a8 0x124f80>;
			opp-microvolt-L2 = <0xc3500 0xc3500 0x124f80>;
			opp-microvolt-L3 = <0xc3500 0xc3500 0x124f80>;
			clock-latency-ns = <0x9c40>;
			opp-suspend;
		};

		opp-1008000000 {
			opp-hz = <0x00 0x3c14dc00>;
			opp-microvolt = <0xd59f8 0xd59f8 0x124f80>;
			opp-microvolt-L0 = <0xd59f8 0xd59f8 0x124f80>;
			opp-microvolt-L1 = <0xcf850 0xcf850 0x124f80>;
			opp-microvolt-L2 = <0xcf850 0xcf850 0x124f80>;
			opp-microvolt-L3 = <0xcf850 0xcf850 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1200000000 {
			opp-hz = <0x00 0x47868c00>;
			opp-microvolt = <0xe7ef0 0xe7ef0 0x124f80>;
			opp-microvolt-L0 = <0xe7ef0 0xe7ef0 0x124f80>;
			opp-microvolt-L1 = <0xe1d48 0xe1d48 0x124f80>;
			opp-microvolt-L2 = <0xdbba0 0xdbba0 0x124f80>;
			opp-microvolt-L3 = <0xd59f8 0xd59f8 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1416000000 {
			opp-hz = <0x00 0x54667200>;
			opp-microvolt = <0xfa3e8 0xfa3e8 0x124f80>;
			opp-microvolt-L0 = <0xfa3e8 0xfa3e8 0x124f80>;
			opp-microvolt-L1 = <0xf4240 0xf4240 0x124f80>;
			opp-microvolt-L2 = <0xf4240 0xf4240 0x124f80>;
			opp-microvolt-L3 = <0xee098 0xee098 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1608000000 {
			opp-hz = <0x00 0x5fd82200>;
			opp-microvolt = <0x10c8e0 0x10c8e0 0x124f80>;
			opp-microvolt-L0 = <0x10c8e0 0x10c8e0 0x124f80>;
			opp-microvolt-L1 = <0x106738 0x106738 0x124f80>;
			opp-microvolt-L2 = <0x100590 0x100590 0x124f80>;
			opp-microvolt-L3 = <0xfa3e8 0xfa3e8 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};

		opp-1800000000 {
			opp-hz = <0x00 0x6b49d200>;
			opp-microvolt = <0x124f80 0x124f80 0x124f80>;
			opp-microvolt-L0 = <0x124f80 0x124f80 0x124f80>;
			opp-microvolt-L1 = <0x11edd8 0x11edd8 0x124f80>;
			opp-microvolt-L2 = <0x118c30 0x118c30 0x124f80>;
			opp-microvolt-L3 = <0x112a88 0x112a88 0x124f80>;
			clock-latency-ns = <0x9c40>;
		};
	};

	opp-table2 {
		compatible = "operating-points-v2";
		nvmem-cells = <0xc9>;
		nvmem-cell-names = "gpu_leakage";
		rockchip,pvtm-voltage-sel = <0x00 0x1d8a8 0x00 0x1d8a9 0x1ea3c 0x01 0x1ea3d 0x1f5f4 0x02 0x1f5f5 0xf423f 0x03>;
		rockchip,pvtm-freq = <0x30d40>;
		rockchip,pvtm-volt = <0xdbba0>;
		rockchip,pvtm-ch = <0x03 0x00>;
		rockchip,pvtm-sample-time = <0x3e8>;
		rockchip,pvtm-number = <0x0a>;
		rockchip,pvtm-error = <0x3e8>;
		rockchip,pvtm-ref-temp = <0x29>;
		rockchip,pvtm-temp-prop = <0x2e 0x0c>;
		rockchip,pvtm-thermal-zone = "gpu-thermal";
		phandle = <0x9e>;

		opp-200000000 {
			opp-hz = <0x00 0xbebc200>;
			opp-microvolt = "\0\f5";
			opp-microvolt-L0 = "\0\f5";
			opp-microvolt-L1 = "\0\f5";
			opp-microvolt-L2 = "\0\f5";
			opp-microvolt-L3 = "\0\f5";
		};

		opp-300000000 {
			opp-hz = <0x00 0x11e1a300>;
			opp-microvolt = "\0\f5";
			opp-microvolt-L0 = "\0\f5";
			opp-microvolt-L1 = "\0\f5";
			opp-microvolt-L2 = "\0\f5";
			opp-microvolt-L3 = "\0\f5";
		};

		opp-400000000 {
			opp-hz = <0x00 0x17d78400>;
			opp-microvolt = <0xc96a8>;
			opp-microvolt-L0 = <0xc96a8>;
			opp-microvolt-L1 = <0xc96a8>;
			opp-microvolt-L2 = "\0\f5";
			opp-microvolt-L3 = "\0\f5";
		};

		opp-600000000 {
			opp-hz = <0x00 0x23c34600>;
			opp-microvolt = <0xe1d48>;
			opp-microvolt-L0 = <0xe1d48>;
			opp-microvolt-L1 = <0xe1d48>;
			opp-microvolt-L2 = <0xdbba0>;
			opp-microvolt-L3 = <0xdbba0>;
		};

		opp-800000000 {
			opp-hz = <0x00 0x2faf0800>;
			opp-microvolt = <0x10c8e0>;
			opp-microvolt-L0 = <0x10c8e0>;
			opp-microvolt-L1 = <0x106738>;
			opp-microvolt-L2 = <0x100590>;
			opp-microvolt-L3 = <0xfa3e8>;
		};
	};

	opp-table3 {
		compatible = "operating-points-v2";
		phandle = <0x93>;

		opp-200000000 {
			opp-hz = <0x00 0xbebc200>;
			opp-microvolt = <0xdbba0>;
		};

		opp-300000000 {
			opp-hz = <0x00 0x11e1a300>;
			opp-microvolt = <0xdbba0>;
		};

		opp-400000000 {
			opp-hz = <0x00 0x17d78400>;
			opp-microvolt = <0xdbba0>;
		};

		opp-528000000 {
			opp-hz = <0x00 0x1f78a400>;
			opp-microvolt = <0xdbba0>;
		};

		opp-600000000 {
			opp-hz = <0x00 0x23c34600>;
			opp-microvolt = <0xdbba0>;
		};

		opp-800000000 {
			opp-hz = <0x00 0x2faf0800>;
			opp-microvolt = <0xdbba0>;
		};
	};

	vcc5v0-sys {
		compatible = "regulator-fixed";
		regulator-name = "vcc5v0_sys";
		regulator-min-microvolt = <0x4c4b40>;
		regulator-max-microvolt = <0x4c4b40>;
		regulator-always-on;
		regulator-boot-on;
		phandle = <0x33>;
	};

	vcc3v3-sys {
		compatible = "regulator-fixed";
		regulator-name = "vcc3v3_sys";
		regulator-min-microvolt = <0x325aa0>;
		regulator-max-microvolt = <0x325aa0>;
		regulator-always-on;
		regulator-boot-on;
		vin-supply = <0x33>;
		phandle = <0x38>;
	};

	vcc5v0-host-usb3-regulator {
		compatible = "regulator-fixed";
		enable-active-high;
		gpio = <0x3c 0x06 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0xca>;
		regulator-name = "vcc5v0_host_usb3";
		regulator-always-on;
	};

	vcc5v0-host-usb2-regulator {
		compatible = "regulator-fixed";
		enable-active-high;
		gpio = <0x3c 0x08 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0xcb>;
		regulator-name = "vcc5v0_host_usb2";
		regulator-always-on;
		phandle = <0x2d>;
	};

	vcc-sd {
		compatible = "regulator-fixed";
		enable-active-high;
		gpio = <0x3c 0x01 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0xcc>;
		regulator-name = "vcc_sd";
		regulator-min-microvolt = <0x325aa0>;
		regulator-max-microvolt = <0x325aa0>;
		phandle = <0x1f>;
	};

	vcc-phy-regulator {
		compatible = "regulator-fixed";
		regulator-name = "vcc_phy";
		regulator-always-on;
		regulator-boot-on;
		phandle = <0x17>;
	};

	vdd-log {
		compatible = "pwm-regulator";
		regulator-name = "vdd_log";
		regulator-min-microvolt = <0xdbba0>;
		regulator-max-microvolt = <0xdbba0>;
		regulator-always-on;
		regulator-boot-on;
	};

	external-gmac-clock {
		compatible = "fixed-clock";
		clock-frequency = <0x7735940>;
		clock-output-names = "clkin_gmac";
		#clock-cells = <0x00>;
		phandle = <0x19>;
	};

	sdio-pwrseq {
		compatible = "mmc-pwrseq-simple";
		clocks = <0xcd 0x01>;
		clock-names = "ext_clock";
		pinctrl-names = "default";
		pinctrl-0 = <0xce>;
		reset-gpios = <0x3c 0x0a 0x01>;
		phandle = <0x1b>;
	};

	wireless-wlan {
		compatible = "wlan-platdata";
		rockchip,grf = <0x15>;
		wifi_chip_type = "ap6255";
		sdio_vref = <0x708>;
		WIFI,host_wake_irq = <0x3c 0x03 0x00>;
		WIFI,work_led_gpio = <0xcf 0x1b 0x00>;
		status = "okay";
	};

	wireless-bluetooth {
		compatible = "bluetooth-platdata";
		clocks = <0xcd 0x01>;
		clock-names = "ext_clock";
		uart_rts_gpios = <0xcf 0x13 0x01>;
		pinctrl-names = "default\0rts_gpio";
		pinctrl-0 = <0xd0>;
		pinctrl-1 = <0xd1>;
		BT,reset_gpio = <0x3c 0x09 0x00>;
		BT,wake_gpio = <0xcf 0x1a 0x00>;
		BT,wake_host_irq = <0x3c 0x04 0x00>;
		BT,work_led_gpio = <0xcf 0x1c 0x00>;
		status = "okay";
	};

	backlight {
		compatible = "pwm-backlight";
		pwms = <0xd2 0x00 0x61a8 0x00>;
		brightness-levels = <0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09 0x0a 0x0b 0x0c 0x0d 0x0e 0x0f 0x10 0x11 0x12 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f 0x20 0x21 0x22 0x23 0x24 0x25 0x26 0x27 0x28 0x29 0x2a 0x2b 0x2c 0x2d 0x2e 0x2f 0x30 0x31 0x32 0x33 0x34 0x35 0x36 0x37 0x38 0x39 0x3a 0x3b 0x3c 0x3d 0x3e 0x3f 0x40 0x41 0x42 0x43 0x44 0x45 0x46 0x47 0x48 0x49 0x4a 0x4b 0x4c 0x4d 0x4e 0x4f 0x50 0x51 0x52 0x53 0x54 0x55 0x56 0x57 0x58 0x59 0x5a 0x5b 0x5c 0x5d 0x5e 0x5f 0x60 0x61 0x62 0x63 0x64 0x65 0x66 0x67 0x68 0x69 0x6a 0x6b 0x6c 0x6d 0x6e 0x6f 0x70 0x71 0x72 0x73 0x74 0x75 0x76 0x77 0x78 0x79 0x7a 0x7b 0x7c 0x7d 0x7e 0x7f 0x80 0x81 0x82 0x83 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 0x91 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 0xad 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 0xb8 0xb9 0xba 0xbb 0xbc 0xbd 0xbe 0xbf 0xc0 0xc1 0xc2 0xc3 0xc4 0xc5 0xc6 0xc7 0xc8 0xc9 0xca 0xcb 0xcc 0xcd 0xce 0xcf 0xd0 0xd1 0xd2 0xd3 0xd4 0xd5 0xd6 0xd7 0xd8 0xd9 0xda 0xdb 0xdc 0xdd 0xde 0xdf 0xe0 0xe1 0xe2 0xe3 0xe4 0xe5 0xe6 0xe7 0xe8 0xe9 0xea 0xeb 0xec 0xed 0xee 0xef 0xf0 0xf1 0xf2 0xf3 0xf4 0xf5 0xf6 0xf7 0xf8 0xf9 0xfa 0xfb 0xfc 0xfd 0xfe 0xff>;
		default-brightness-level = <0xc8>;
		status = "okay";
		phandle = <0xb7>;
	};

	gpio-leds {
		compatible = "gpio-leds";
		pinctrl-names = "default";
		pinctrl-0 = <0xd3>;

		led@1 {
			gpios = <0x3c 0x02 0x00>;
			label = "system_work_led1";
			retain-state-suspended;
		};

		led@2 {
			gpios = <0x3c 0x0c 0x00>;
			label = "system_work_led2";
			retain-state-suspended;
		};

		led@3 {
			gpios = <0x3c 0x0d 0x00>;
			label = "system_work_led3";
			retain-state-suspended;
		};

		led@4 {
			gpios = <0xcf 0x1b 0x00>;
			label = "wifi_work_led";
		};

		led@5 {
			gpios = <0xcf 0x1c 0x00>;
			label = "bt_work_led";
		};
	};

	rk-headset {
		compatible = "rockchip_headset";
		headset_gpio = <0x3d 0x1c 0x00>;
		spk_con_gpio = <0x3c 0x0b 0x00>;
		pinctrl-names = "default";
		pinctrl-0 = <0xd4>;
		io-channels = <0xd5 0x02>;
	};

	rt5651-sound {
		status = "okay";
		compatible = "simple-audio-card";
		simple-audio-card,format = "i2s";
		simple-audio-card,name = "realtek,rt5651-codec";
		simple-audio-card,mclk-fs = <0x100>;
		simple-audio-card,widgets = "Microphone\0Mic Jack\0Headphone\0Headphone Jack";
		simple-audio-card,routing = "Mic Jack\0MICBIAS1\0IN1P\0Mic Jack\0Headphone Jack\0HPOL\0Headphone Jack\0HPOR";

		simple-audio-card,cpu {
			sound-dai = <0xd6>;
		};

		simple-audio-card,codec {
			sound-dai = <0xd7>;
		};
	};

	rockchip-msm261s4030h0-codec {
		status = "okay";
		compatible = "rockchip-msm261s4030h0-codec";
		phandle = <0xd8>;
	};

	rockchip-msm261s4030h0 {
		compatible = "rockchip-msm261s4030h0";
		status = "okay";
		rockchip,codec = <0xd8>;
		rockchip,cpu = <0xd9>;
	};

	chosen {
		bootargs = "earlycon=uart8250,mmio32,0xff1a0000 swiotlb=1";
	};

	cpuinfo {
		compatible = "rockchip,cpuinfo";
		nvmem-cells = <0xda>;
		nvmem-cell-names = "id";
	};

	ramoops_mem {
		reg = <0x00 0x110000 0x00 0xf0000>;
		reg-names = "ramoops_mem";
		phandle = <0xdb>;
	};

	ramoops {
		compatible = "ramoops";
		record-size = <0x00 0x20000>;
		console-size = <0x00 0x80000>;
		ftrace-size = <0x00 0x00>;
		pmsg-size = <0x00 0x50000>;
		memory-region = <0xdb>;
	};

	fiq-debugger {
		compatible = "rockchip,fiq-debugger";
		rockchip,serial-id = <0x02>;
		rockchip,wake-irq = <0x00>;
		rockchip,irq-mode-enable = <0x00>;
		rockchip,baudrate = <0x16e360>;
		pinctrl-names = "default";
		pinctrl-0 = <0x4b>;
		interrupts = <0x00 0x96 0x04 0x00>;
	};

	reserved-memory {
		#address-cells = <0x02>;
		#size-cells = <0x02>;
		ranges;

		drm-logo@00000000 {
			compatible = "rockchip,drm-logo";
			reg = <0x00 0x00 0x00 0x00>;
			phandle = <0xc0>;
		};

		secure-memory@20000000 {
			compatible = "rockchip,secure-memory";
			reg = <0x00 0x20000000 0x00 0x10000000>;
			status = "disabled";
			phandle = <0xc1>;
		};

		stb-devinfo@00000000 {
			compatible = "rockchip,stb-devinfo";
			reg = <0x00 0x00 0x00 0x00>;
		};
	};

	rockchip-key {
		compatible = "rockchip,key";
		status = "okay";
		io-channels = <0xd5 0x01>;

		vol-up-key {
			linux,code = <0x73>;
			label = "volume up";
			rockchip,adc_value = <0x01>;
		};

		vol-down-key {
			linux,code = <0x72>;
			label = "volume down";
			rockchip,adc_value = <0xaa>;
		};

		power-key {
			gpios = <0x3c 0x05 0x01>;
			linux,code = <0x74>;
			label = "power";
			gpio-key,wakeup;
		};

		menu-key {
			linux,code = <0x3b>;
			label = "menu";
			rockchip,adc_value = <0x2ea>;
		};

		home-key {
			linux,code = <0x66>;
			label = "home";
			rockchip,adc_value = <0x163>;
		};

		back-key {
			linux,code = <0x9e>;
			label = "back";
			rockchip,adc_value = <0x230>;
		};

		camera-key {
			linux,code = <0xd4>;
			label = "camera";
			rockchip,adc_value = <0x1c2>;
		};
	};

	isp@ff910000 {
		compatible = "rockchip,rk3399-isp\0rockchip,isp";
		reg = <0x00 0xff910000 0x00 0x4000>;
		interrupts = <0x00 0x2b 0x04 0x00>;
		clocks = <0x08 0x89 0x08 0x89 0x08 0xa4 0x08 0x77 0x08 0xe7 0x08 0xe9 0x08 0x1e1 0x08 0x1e3 0x08 0x6e 0x08 0xa5>;
		clock-names = "clk_cif_out\0clk_cif_pll\0pclk_dphytxrx\0pclk_dphy_ref\0aclk_isp0_noc\0aclk_isp0_wrapper\0hclk_isp0_noc\0hclk_isp0_wrapper\0clk_isp0\0pclk_dphyrx";
		pinctrl-names = "cif_clkout\0isp_dvp8bit0\0isp_mipi_fl\0isp_mipi_fl_prefl\0isp_flash_as_gpio\0isp_flash_as_trigger_out";
		pinctrl-0 = <0xdc>;
		pinctrl-1 = <0xdc 0xdd>;
		pinctrl-2 = <0xdc>;
		pinctrl-3 = <0xdc 0xde>;
		pinctrl-4 = <0xdf>;
		pinctrl-5 = <0xe0>;
		rockchip,isp,mipiphy = <0x02>;
		rockchip,isp,cifphy = <0x01>;
		rockchip,isp,dsiphy,reg = <0xff968000 0x8000>;
		rockchip,grf = <0x15>;
		rockchip,cru = <0x08>;
		rockchip,gpios = <0x35 0x03 0x00>;
		rockchip,isp,iommu-enable = <0x01>;
		power-domains = <0x16 0x13>;
		iommus = <0xaf>;
		status = "disabled";
	};

	isp@ff920000 {
		compatible = "rockchip,rk3399-isp\0rockchip,isp";
		reg = <0x00 0xff920000 0x00 0x4000>;
		interrupts = <0x00 0x2c 0x04 0x00>;
		clocks = <0x08 0xe8 0x08 0xea 0x08 0x1e2 0x08 0x1e4 0x08 0x6f 0x08 0x89 0x08 0x89 0x08 0xa4 0x08 0x77 0x08 0x17b 0x08 0xa5 0x08 0x171 0x08 0x78>;
		clock-names = "aclk_isp1_noc\0aclk_isp1_wrapper\0hclk_isp1_noc\0hclk_isp1_wrapper\0clk_isp1\0clk_cif_out\0clk_cif_pll\0pclk_dphytxrx\0pclk_dphy_ref\0pclk_isp1\0pclk_dphyrx\0pclk_mipi_dsi\0mipi_dphy_cfg";
		pinctrl-names = "cif_clkout\0isp_dvp8bit0\0isp_mipi_fl\0isp_mipi_fl_prefl\0isp_flash_as_gpio\0isp_flash_as_trigger_out";
		pinctrl-0 = <0xdc>;
		pinctrl-1 = <0xdd>;
		pinctrl-2 = <0xdc>;
		pinctrl-3 = <0xde>;
		pinctrl-4 = <0xdf>;
		pinctrl-5 = <0xe0>;
		rockchip,isp,mipiphy = <0x02>;
		rockchip,isp,cifphy = <0x01>;
		rockchip,isp,dsiphy,reg = <0xff968000 0x8000>;
		rockchip,grf = <0x15>;
		rockchip,cru = <0x08>;
		rockchip,gpios = <0x35 0x03 0x00>;
		rockchip,isp,iommu-enable = <0x01>;
		power-domains = <0x16 0x14>;
		iommus = <0xb0>;
		status = "disabled";
	};

	uboot-charge {
		compatible = "rockchip,uboot-charge";
		rockchip,uboot-charge-on = <0x01>;
		rockchip,android-charge-on = <0x00>;
	};

	hdmi-dp-sound {
		status = "disabled";
		compatible = "rockchip,rk3399-hdmi-dp";
		rockchip,cpu = <0xe1>;
		rockchip,codec = <0xe2 0xe3>;
	};

	firmware {

		android {
			compatible = "android,firmware";

			fstab {
				compatible = "android,fstab";

				system {
					compatible = "android,system";
					dev = "/dev/block/platform/fe330000.sdhci/by-name/system";
					type = "ext4";
					mnt_flags = "ro,barrier=1,inode_readahead_blks=8";
					fsmgr_flags = "wait,verify";
				};

				vendor {
					compatible = "android,vendor";
					dev = "/dev/block/platform/fe330000.sdhci/by-name/vendor";
					type = "ext4";
					mnt_flags = "ro,barrier=1,inode_readahead_blks=8";
					fsmgr_flags = "wait,verify";
				};
			};
		};
	};

	cif_isp@ff910000 {
		compatible = "rockchip,rk3399-cif-isp";
		rockchip,grf = <0x15>;
		reg = <0x00 0xff910000 0x00 0x4000 0x00 0xff968000 0x00 0x8000>;
		reg-names = "register\0dsihost-register";
		clocks = <0x08 0xe7 0x08 0xe9 0x08 0x1e1 0x08 0x1e3 0x08 0x6e 0x08 0xa5 0x08 0x89 0x08 0x89 0x08 0x77>;
		clock-names = "aclk_isp0_noc\0aclk_isp0_wrapper\0hclk_isp0_noc\0hclk_isp0_wrapper\0clk_isp0\0pclk_dphyrx\0clk_cif_out\0clk_cif_pll\0pclk_dphy_ref";
		interrupts = <0x00 0x2b 0x04 0x00>;
		interrupt-names = "cif_isp10_irq";
		power-domains = <0x16 0x13>;
		rockchip,isp,iommu-enable = <0x01>;
		iommus = <0xaf>;
		status = "okay";
		rockchip,camera-modules-attached = <0xe4>;
	};

	cif_isp@ff920000 {
		compatible = "rockchip,rk3399-cif-isp";
		rockchip,grf = <0x15>;
		reg = <0x00 0xff920000 0x00 0x4000 0x00 0xff968000 0x00 0x8000>;
		reg-names = "register\0dsihost-register";
		clocks = <0x08 0xe8 0x08 0xea 0x08 0x1e2 0x08 0x1e4 0x08 0x6f 0x08 0x17b 0x08 0xa4 0x08 0x171 0x08 0x78 0x08 0x89 0x08 0x89 0x08 0x77>;
		clock-names = "aclk_isp1_noc\0aclk_isp1_wrapper\0hclk_isp1_noc\0hclk_isp1_wrapper\0clk_isp1\0pclkin_isp1\0pclk_dphytxrx\0pclk_mipi_dsi\0mipi_dphy_cfg\0clk_cif_out\0clk_cif_pll\0pclk_dphy_ref";
		interrupts = <0x00 0x2c 0x04 0x00>;
		interrupt-names = "cif_isp10_irq";
		power-domains = <0x16 0x14>;
		rockchip,isp,iommu-enable = <0x01>;
		iommus = <0xb0>;
		status = "okay";
		rockchip,camera-modules-attached = <0xe5>;
	};

	hdmi-codec {
		compatible = "simple-audio-card";
		simple-audio-card,format = "i2s";
		simple-audio-card,mclk-fs = <0x100>;
		simple-audio-card,name = "HDMI-CODEC";
		status = "okay";

		simple-audio-card,cpu {
			sound-dai = <0xe1>;
		};

		simple-audio-card,codec {
			sound-dai = <0xe2>;
		};
	};

	extbrd {
		compatible = "eaidk-extboard";
		io-channels = <0xd5 0x00 0xd5 0x03>;
	};

	vcc-dvdd {
		compatible = "regulator-gpio";
		regulator-name = "vcc_dvdd";
		pinctrl-names = "default";
		pinctrl-0 = <0xe6 0xe7>;
		enable-active-high;
		startup-delay-us = <0x3e8>;
		enable-gpio = <0x35 0x13 0x00>;
		gpios = <0x3d 0x19 0x00>;
		states = <0x124f80 0x00 0x1b7740 0x01>;
		regulator-min-microvolt = <0x124f80>;
		regulator-max-microvolt = <0x1b7740>;
		phandle = <0x40>;
	};

	vcc-avdd-3v2 {
		compatible = "regulator-fixed";
		regulator-name = "vcc_avdd_3v2";
		pinctrl-names = "default";
		pinctrl-0 = <0xe8>;
		enable-active-high;
		startup-delay-us = <0x3e8>;
		gpio = <0x35 0x12 0x00>;
		phandle = <0x41>;
	};
};

```
