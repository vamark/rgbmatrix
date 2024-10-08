#include "options_converter.h"

OptionsConverter::OptionsConverter(JNIEnv *env) {
    this->env = env;
}

rgb_matrix::RGBMatrix::Options OptionsConverter::convert(jobject options) {
    FieldReader optionsReader(env, options);
    rgb_matrix::RGBMatrix::Options nativeOptions;

    std::optional<const char*> hardwareMappingOpt = optionsReader.readString("hardwareMapping");
    if (hardwareMappingOpt.has_value()) {
        nativeOptions.hardware_mapping = hardwareMappingOpt.value();
    }

    std::optional<int> rowsOpt = optionsReader.readInt("rows");
    if (rowsOpt.has_value()) {
        nativeOptions.rows = rowsOpt.value();
    }

    std::optional<int> colsOpt = optionsReader.readInt("cols");
    if (colsOpt.has_value()) {
        nativeOptions.cols = colsOpt.value();
    }

    std::optional<int> chainLengthOpt = optionsReader.readInt("chainLength");
    if (chainLengthOpt.has_value()) {
        nativeOptions.chain_length = chainLengthOpt.value();
    }

    std::optional<int> parallelOpt = optionsReader.readInt("parallel");
    if (parallelOpt.has_value()) {
        nativeOptions.parallel = parallelOpt.value();
    }

    std::optional<int> pwmBitsOpt = optionsReader.readInt("pwmBits");
    if (pwmBitsOpt.has_value()) {
        nativeOptions.pwm_bits = pwmBitsOpt.value();
    }

    std::optional<int> pwmLsbNanosecondsOpt = optionsReader.readInt("pwmLsbNanoseconds");
    if (pwmLsbNanosecondsOpt.has_value()) {
        nativeOptions.pwm_lsb_nanoseconds = pwmLsbNanosecondsOpt.value();
    }

    std::optional<int> pwmDitherBitsOpt = optionsReader.readInt("pwmDitherBits");
    if (pwmDitherBitsOpt.has_value()) {
        nativeOptions.pwm_dither_bits = pwmDitherBitsOpt.value();
    }

    std::optional<int> brightnessOpt = optionsReader.readInt("brightness");
    if (brightnessOpt.has_value()) {
        nativeOptions.brightness = brightnessOpt.value();
    }

    std::optional<int> scanModeOpt = optionsReader.readInt("scanMode");
    if (scanModeOpt.has_value()) {
        nativeOptions.scan_mode = scanModeOpt.value();
    }

    std::optional<int> rowAddressTypeOpt = optionsReader.readInt("rowAddressType");
    if (rowAddressTypeOpt.has_value()) {
        nativeOptions.row_address_type = rowAddressTypeOpt.value();
    }

    std::optional<int> multiplexingOpt = optionsReader.readInt("multiplexing");
    if (multiplexingOpt.has_value()) {
        nativeOptions.multiplexing = multiplexingOpt.value();
    }

    std::optional<bool> disableHardwarePulsingOpt = optionsReader.readBoolean("disableHardwarePulsing");
    if (disableHardwarePulsingOpt.has_value()) {
        nativeOptions.disable_hardware_pulsing = disableHardwarePulsingOpt.value();
    }

    std::optional<bool> showRefreshRateOpt = optionsReader.readBoolean("showRefreshRate");
    if (showRefreshRateOpt.has_value()) {
        nativeOptions.show_refresh_rate = showRefreshRateOpt.value();
    }

    std::optional<bool> inverseColorsOpt = optionsReader.readBoolean("inverseColors");
    if (inverseColorsOpt.has_value()) {
        nativeOptions.inverse_colors = inverseColorsOpt.value();
    }

    std::optional<const char*> ledRgbSequenceOpt = optionsReader.readString("ledRgbSequence");
    if (ledRgbSequenceOpt.has_value()) {
        nativeOptions.led_rgb_sequence = ledRgbSequenceOpt.value();
    }

    std::optional<const char*> pixelMapperConfigOpt = optionsReader.readString("pixelMapperConfig");
    if (pixelMapperConfigOpt.has_value()) {
        nativeOptions.pixel_mapper_config = pixelMapperConfigOpt.value();
    }

    std::optional<const char*> panelTypeOpt = optionsReader.readString("panelType");
    if (panelTypeOpt.has_value()) {
        nativeOptions.panel_type = panelTypeOpt.value();
    }

    std::optional<int> limitRefreshRateHzOpt = optionsReader.readInt("limitRefreshRateHz");
    if (limitRefreshRateHzOpt.has_value()) {
        nativeOptions.limit_refresh_rate_hz = limitRefreshRateHzOpt.value();
    }

    return nativeOptions;
}